# Mesa 7.11.2 for OS/2 (ArcaOS)

Software-rendered OpenGL 2.1 for OS/2 Presentation Manager, built with GCC 9.2
(`i686-pc-os2-emx`, kLIBC). Three DLLs are produced.

OS/2 port by **Martin Iturbide (OS2World)**, 2026. Mesa itself is the work of the
Mesa developers (Brian Paul and many others).

| DLL | What it is | Depends on |
|---|---|---|
| `MesaGL7.dll`  | OpenGL (Mesa core + swrast + OS/2 PM driver, `WMesa*` API) | libc, libm, libstdc++, PM (via `libos2`) |
| `libGLU7.dll`  | GLU (SGI GLU, includes the C++ NURBS code)                 | `MesaGL7.dll` |
| `libGLUT7.dll` | GLUT backend for PM (single window)                        | `MesaGL7.dll`, `libGLU7.dll` |

Applications link to them at load time, so the DLLs show up as imports in PMDLL.
The demo `demos\glutcube\glutcube.exe` is the reference consumer; `demos\` also
has `gears`, `shapes` and `texture` (see [Demos](#demos)).

`MesaGL7.dll` also contains **OSMesa**, Mesa's off-screen driver: it renders into a
memory buffer you provide, with no window system involved. Together with DIVE this
is the "software OpenGL + fast blit" route for porting OpenGL programs; see
[OSMesa and DIVE](#osmesa-and-dive).

## Status and limitations

* **Version:** Mesa 7.11.2 (OpenGL 2.1 API, software rasteriser) with an OS/2 PM
  driver, a PM GLUT and the stock SGI GLU. Port release 1.1.
* **Tested:** the four demos below, on ArcaOS 5.1.1 in a VirtualBox VM
  (32-bit colour, software rendering). Not yet tested on real hardware or other
  OS/2 flavours.
* **GLSL / extensions:** the GLSL compiler and the usual Mesa extensions are part of
  the build, but no shader programs or extension-heavy applications have been tried.
* **Software rendering only.** Speed is modest: roughly 10 ms of CPU per frame for a
  400x400 window in the VM. There is no hardware path. The PM driver blits with GPI;
  for DIVE use OSMesa as shown in the `osdive` demo (not built into the PM driver).
* **GLUT:** one window; menus, overlays, game mode and video resize are stubs;
  `glutIdleFunc` animation is capped at 30 fps (see `GLUT_FPS`).
* **Not binary compatible with the old Mesa 5.0 port:** the DLLs are `MesaGL7.dll`,
  `libGLU7.dll` and `libGLUT7.dll`, not the monolithic `MesaGL2.DLL`. Programs must be
  relinked against the import libraries.
* **Open Watcom:** only GCC import libraries (`*_imp.a`) are provided.

## Using a binary release

1. Copy `MesaGL7.dll`, `libGLU7.dll` and `libGLUT7.dll` to a directory on `LIBPATH`
   (or next to your exe).
2. Compile with `-Iinclude` and the `-fno-builtin-sin/cos` flags, and link with
   `lib/libGLUT7_imp.a lib/MesaGL7_imp.a lib/libGLU7_imp.a` (see
   [Building an application](#building-an-application)).

## Source layout (OS/2-specific parts)

| Path | Purpose |
|---|---|
| `src/mesa/drivers/os2/`        | PM driver (`os2mesa.c`, `os2mesa.h`, `os2_config.h`, `os2_compat/`) |
| `src/glut/os2/os2_glut.c`      | GLUT API on top of PM + the `WMesa*` driver |
| `Makefile.os2`, `Makefile.os2glu`, `Makefile.os2glut` | compile + link rules for each DLL |
| `MesaGL7.def`, `libGLU7.def`, `libGLUT7.def` | DLL export lists (`glFoo=_glFoo`) |
| `MesaGL7_imp.def`, `libGLU7_imp.def`, `libGLUT7_imp.def` | same lists with the sides swapped, used by `emximp` to make import libraries |
| `mesagl.rsp`, `glu.rsp`, `glut.rsp` | object lists for each DLL link (`@file` response files) |
| `demos/`                       | demo programs and their build script (`build_demos.cmd`) |
| `dev/`                         | optional helpers for building over ssh in a VM (see below) |

Generated directories (not part of the source release): `obj_os2/`, `obj_glu/`,
`obj_glut/` (OMF objects), `lib/` (static libs `*.a` and import libs `*_imp.a`) and
`dll/` (the DLLs and link maps). The `lib/` import libraries are also rebuilt by
`link_dlls.cmd`.

## Prerequisites

Install through ANPM: `gcc`/`g++` 9.x, GNU `make` 4.x, `binutils` (`ar`, `emximp`,
`emxomfld`), `tee`, and the OS/2 Toolkit headers (`C:\usr\include\os2tk45`).
Open Watcom's `wl.exe` (WLINK) is used by `emxomfld` as the actual linker.

Every build script sets:

```
set EMXOMFLD_TYPE=WLINK
set EMXOMFLD_LINKER=wl.exe
set EMXOMFLD_PRELINK=0
```

## Building

All commands run from the Mesa root directory. Each script writes a log next to it
(via `tee`), so results can be checked afterwards.

| Script | What it does | Log |
|---|---|---|
| `build_dlls.cmd`   | Full rebuild: clean + compile all three libraries, then calls `link_dlls.cmd` | `build_dlls.log` (includes the link log) |
| `rebuild_gl.cmd`   | Incremental: recompile only changed sources, relink all DLLs, copy them to `demos\glutcube\` (copy to the other demo folders yourself) | `rebuild_gl.log` |
| `link_dlls.cmd`    | Link step only (objects already compiled); also regenerates the import libraries | `link_dlls.log` |
| `compile_mesagl.cmd`, `compile_glu.cmd`, `compile_glut.cmd` | Per-library clean + compile + `make dll` | `compile_*.log` |

A full build compiles about 260 Mesa objects plus GLU and GLUT and takes 10-15
minutes in the VM. Link order matters because each DLL imports the previous one:

1. `MesaGL7.dll`, then `emximp` makes `lib/MesaGL7_imp.a`
2. `libGLU7.dll` (links `MesaGL7_imp.a`), then `lib/libGLU7_imp.a`
3. `libGLUT7.dll` (links both import libs)

The link commands (also in the Makefile `dll:` targets):

```
gcc -Zomf -Zdll -Zmap=dll/MesaGL7  -o dll/MesaGL7.dll  @mesagl.rsp MesaGL7.def -lstdc++ -los2 -lm
emximp -o lib/MesaGL7_imp.a MesaGL7_imp.def
gcc -Zomf -Zdll -Zmap=dll/libGLU7  -o dll/libGLU7.dll  @glu.rsp libGLU7.def lib/MesaGL7_imp.a -lstdc++ -los2 -lm
emximp -o lib/libGLU7_imp.a libGLU7_imp.def
gcc -Zomf -Zdll -Zmap=dll/libGLUT7 -o dll/libGLUT7.dll @glut.rsp libGLUT7.def lib/libGLU7_imp.a lib/MesaGL7_imp.a -lstdc++ -los2 -lm
```

`-Zdll` makes `emxomfld` supply the kLIBC runtime and `-los2` the PM imports
(`WinXxx`, `GpiXxx`, `DevXxx`). Do **not** link the DLLs with a bare `wl.exe` and
`OPTION UNDEFSOK`: every libc/PM/GL reference then stays unresolved and the DLL
crashes at the first call.

Make the import libraries from the `*_imp.def` files, **not** with
`emximp -o x_imp.a x.dll`: a DLL's exports are plain `glFoo`, so stubs made from the
DLL define `glFoo` and the objects (which reference `_glFoo`) fail to link.

### Compiler flags that matter

Compile everything that calls `sin`/`cos` (all Mesa, GLU, GLUT sources and any
application) with:

```
-fno-builtin-sinf -fno-builtin-cosf -fno-builtin-sin -fno-builtin-cos
```

At `-O2` GCC merges a `sinf(a)` + `cosf(a)` pair on the same argument into one call
to `cexpf()` (the `cexpi` builtin). This platform's libm returns NaN for that call,
so every vertex computed that way becomes NaN and the picture is silently empty or
wrong. The flags are already set in `Makefile.os2`, `Makefile.os2glu`,
`Makefile.os2glut` and `demos/build_demos.cmd`. Symptom to look for: `cosf(x)` is
correct in isolation but `NaN` in an optimised loop, or `_cexp`/`_cexpf` shows up
in a link map.

## Building an application

Application symbols are OMF `_glFoo`; the DLLs export plain `glFoo`. The `*_imp.a`
import libraries bridge that. See `demos/glutcube/compile_glutcube.cmd`:

```
emximp -o lib\libGLUT7_imp.a libGLUT7_imp.def     (and MesaGL7, libGLU7)
gcc -Wall -O2 -Zomf -c glutcube.c -I..\..\include
gcc -Zomf -o glutcube.exe glutcube.def glutcube.o ^
    ..\..\lib\libGLUT7_imp.a ..\..\lib\MesaGL7_imp.a ..\..\lib\libGLU7_imp.a -lm
```

* The app's `.def` must contain `NAME <name> WINDOWAPI` so the exe is a PM
  application (GLUT creates a PM message queue).
* At run time the three DLLs must be found by the loader (same directory as the
  exe, or on `LIBPATH`).
* The calling convention of GL, GLU and GLUT is plain cdecl on this port
  (`GLAPIENTRY`/`GLUTAPIENTRY` are empty under GCC).
* Add the `-fno-builtin-sin/cos` flags above to the application's compile line.

## Demos

All demos link with the same three import libraries and are built by
`demos\build_demos.cmd` (log: `demos\build_demos.log`, which also copies the DLLs
next to each exe). Run from the exe's own directory so the DLLs are found.

| Demo | Shows | Keys |
|---|---|---|
| `glutcube` | smoothly shaded rotating cube, idle callback, depth test | q/ESC |
| `gears` | classic three gears: lighting, display lists, flat/smooth shading, `glFrustum`; prints FPS to stderr every 5 s | arrows rotate, `z`/`Z` spin, ESC |
| `shapes` | the eight GLUT solids/wireframes (teapot, sphere, torus, cone, cube, dodeca-, icosa-, octahedron), lighting toggle, bitmap-font overlay, `glutTimerFunc`, mouse drag, special keys | `1`-`8` shape, `w` wire, `l` light, space pause, drag rotates, up/down speed, ESC |
| `texture` | texture mapping with `gluBuild2DMipmaps`, nearest/linear/mipmap filters, alpha blending | `f` filter, `b` blend, space pause, ESC |
| `osmesa_test` | headless OSMesa smoke test (console program, no window): clear, flat triangle, lit GLU sphere, depth test; checks the pixels and writes `osmesa_test.ppm`; exit code 0 = all passed | - |
| `osdive` | OSMesa renders into memory, DIVE blits it scaled to the window; shows the fps in the title; usage `osdive [width height]` (render size, default 320x240) | space pause, ESC; resize the window to see DIVE scale |

The sources of
gears, shapes and texture were written for this port (the official MesaDemos
package is no longer published for 7.11.2; the nearest is `mesa-demos-8.0.1`).

## OSMesa and DIVE

OSMesa is Mesa's window-system-independent driver: OpenGL calls render into a
buffer in ordinary memory. It lives in `MesaGL7.dll` and its 11 `OSMesa*` functions
are declared in `GL/osmesa.h` and exported through the same import library
(`lib/MesaGL7_imp.a`). A minimal off-screen render:

```c
#include <GL/gl.h>
#include <GL/osmesa.h>

unsigned char *buf = malloc(W * H * 4);
OSMesaContext ctx = OSMesaCreateContextExt(OSMESA_RGBA, 16 /*depth*/, 0, 0, NULL);
OSMesaMakeCurrent(ctx, buf, GL_UNSIGNED_BYTE, W, H);
OSMesaPixelStore(OSMESA_Y_UP, 0);     /* optional: first row = top of the image */
/* ... normal OpenGL calls, then glFinish() ... pixels are now in buf ... */
OSMesaDestroyContext(ctx);
```

Showing that buffer fast with DIVE (see `demos/osdive/osdive.c`, which follows the
DIVEDemo sample for the visible-region handling):

1. Allocate the pixel buffer yourself (`DosAllocMem`) with a width that is a
   multiple of 8, create the OSMesa context with `OSMESA_BGRA` and call
   `OSMesaMakeCurrent` on that buffer.
2. Associate the buffer with DIVE: `DiveAllocImageBuffer(hDive, &num, FOURCC_BGR4,
   w, h, 0, buffer)`. OSMesa's `OSMESA_BGRA` byte order is exactly DIVE's
   `FOURCC_BGR4`, so no pixel conversion is needed. With `OSMESA_Y_UP = 0` the rows
   are top-down, as DIVE expects.
3. Each frame: render with OpenGL, call `glFinish()`, then
   `DiveBlitImage(hDive, num, DIVE_BUFFER_SCREEN)`.
4. Set the blitter up with `DiveSetupBlitter` using the window's visible-region
   rectangles (`WinSetVisibleRegionNotify`, handle `WM_VRNDISABLED`/`WM_VRNENABLED`).
   Set the destination size to the window size and DIVE scales the image: render at
   a small fixed resolution and let DIVE stretch it, as many engines do.

Build such a program with the three import libraries plus `-L%UNIXROOT%/os2tk45/lib
-lmmpm2` (for `dive`). DIVE needs a desktop of at least 15-bit colour.

Notes:

* `OSMesaCreateContextExt` and `OSMesaMakeCurrent` reset the FPU (see Runtime
  notes), so OSMesa programs do not need GLUT for that.
* OSMesa renders with the same software rasteriser as the PM driver; it has no
  window, so you drive the message loop and the blit yourself.
* Mesa is built with 8-bit channels, so use `GL_UNSIGNED_BYTE` buffers.

## Runtime notes

* `GLUT_FPS=<1..1000>` caps the GLUT main loop frame rate (default 30). The loop
  would otherwise spin at 100% CPU when an idle callback is registered. Cost is
  roughly 10 ms of CPU per frame for a ~400x400 window: about 63% CPU at 60 fps and
  about 32% at 30 fps in the ArcaOS VM.
* OS/2 starts threads with the x87 control word at `0x0362`, i.e. invalid-operation,
  divide-by-zero, overflow and underflow exceptions **unmasked**. Mesa and libm assume
  the C/IEEE default (all masked), so without a reset a pending exception kills the
  program with `SIGFPE` inside libc (`LDMXCSR` + `WAIT`) the first time `cosf` and
  friends run. `glutInit()` (and the end of `glutCreateWindow()`) therefore execute
  `fninit` and reset `MXCSR` to `0x1F80`. Applications that bypass GLUT must do the
  same.
* Rendering is double buffered in system memory; each swap does
  `WinGetPS` + `GpiDrawBits` into the window, so nothing keeps a long-lived PS.
* GLUT supports one window; menus, overlays, game mode and video-resize calls are
  stubs.

## Optional: building and testing in a VM over ssh

The port was developed by editing on a Windows host and building in an ArcaOS
VirtualBox VM that shares the source folder and runs an ssh server (reached through a
NAT port forward). If you work that way: the ssh shell lacks the environment an
interactive session has, so wrap commands in a `.cmd` that sets it. `dev\vmroot.cmd`
(runs from the Mesa root) and `dev\vmenv.cmd` do this; `dev\vmdemo.cmd <demo>`
starts a demo. They contain the author's paths, so adjust them. The environment
they set is:

```
set UNIXROOT=C:
set EMXOMFLD_TYPE=WLINK ... (see above)
set PATH=C:\usr\bin;%PATH%
set C_INCLUDE_PATH=C:/usr/include;C:/usr/include/os2tk45
set CPLUS_INCLUDE_PATH=C:/usr/include;C:/usr/include/os2tk45
set LIBRARY_PATH=C:/usr/lib
```

`UNIXROOT` is required: the OS/2 compat headers include `/@unixroot/usr/include/...`.

Practical tips:

* `detach` returns immediately but proved unreliable for programs that write to
  stderr (the app was killed when the ssh session ended). What works: run the exe in
  the foreground and put the whole ssh call in the background of the calling shell,
  redirecting its output to a file, e.g.
  `( ssh ... "cd demos\gears&gears.exe" > out.txt 2>&1 & )`. The ssh `timeout`
  only ends the session; close the app itself with Alt+F4 (VBoxManage
  `keyboardputscancode 38 3e be b8`).
* Close the demo before rebuilding; a running exe locks the DLLs.
* Set variables for a single command through a `.cmd` file; inline
  `set A=1 & set B=2 & cmd` chains over ssh get mangled (and a space before `&`
  becomes part of the value).
* OS/2 `cmd` has no `copy /y`, no `tail`/`grep` in cmd pipelines, and expands
  `%VAR%` at line-parse time (do not set and use a variable on one `&` line).
* Do not leave the cube running while building: it competes for CPU.

## Troubleshooting

| Symptom | Likely cause |
|---|---|
| Crash with `EIP` at a tiny address (`0x39`, `0`) or on the stack | unresolved externals in a DLL. Look for `W1028 ... undefined reference` in `dll\*.map`, or `undefined symbol` in the link log |
| `_GpiFoo@24` undefined | `_System`/`EXPENTRY` were overridden to stdcall. On this GCC `_System` is already the native OS/2 linkage; `os2_config.h` must not redefine it |
| `fatal error: /@unixroot/usr/include/...` | `UNIXROOT` not set (ssh shell) |
| `undefined symbol __Znwj`, `___gxx_personality_v0`, `__cxxabiv1...` | link is missing `-lstdc++` (Mesa's GLSL and GLU NURBS code is C++) |
| `Duplicate symbol ___gl_pqHeapNewPriorityQ` | `tess_priorityq_heap.o` was linked; `priorityq.c` already includes it, so leave it out of `glu.rsp` |
| `E3033: directive error` from WLINK | stray space in an `EMXOMFLD_*` value, or a `rem` comment in a WLINK script (WLINK uses `#`) |
| Window opens but the client area is empty | blit using a released PS; the current `os2mesa_blit` acquires a fresh PS per swap |
| Window opens but the scene is empty and a probe triangle works | geometry computed with `sinf`/`cosf` pairs is NaN: rebuild with the `-fno-builtin-sinf -fno-builtin-cosf ...` flags (see Compiler flags) |
| `SIGFPE` / `C0000097 Float Invalid Operation` in `LIBCN0` right after start | x87 exceptions unmasked (control word `0x0362`); `glutInit` resets the FPU, so check the app calls `glutInit` first |
| `undefined symbol _glFoo` when linking an app or GLUT/GLU | import library missing or made from the DLL instead of the `*_imp.def` file; rerun `link_dlls.cmd` |
| Demos link but crash after a full rebuild | `build_dlls.cmd` must finish its link phase (check `build_dlls.log` for `undefined symbol` lines) and the new DLLs must be copied into each demo folder |
| VM sluggish / ssh hangs | a demo is spinning at 100% CPU; close it (Alt+F4) |

## History

An earlier attempt linked the DLLs with raw WLINK scripts and no libraries, then
tried wlib import stubs, `.def` `IMPORTS` sections and a runtime
`DosLoadModule` shim to get around the resulting crashes. All of that was
removed once the real cause (unresolved externals in the DLLs) was fixed.

Later bring-up of the extra demos found two more platform problems, both now
handled in the build: the `cexpf` rewrite of `sin`/`cos` pairs (all-NaN geometry)
and OS/2's unmasked x87 exceptions (`SIGFPE` in libc).

## Changes from upstream Mesa 7.11.2

* `src/mesa/main/querymatrix.c`: one condition changed to
  `#elif !defined(FP_NAN) && (...)` so it compiles with this libc.
* New: `src/mesa/drivers/os2/` (PM driver and compat headers), `src/glut/os2/`
  (PM GLUT), the `Makefile.os2*`, `.def`, `.rsp` and `.cmd` files in the root, the
  `demos/` and `dev/` folders and this README.
* `src/mesa/drivers/osmesa/osmesa.c` (release 1.1): now compiled into `MesaGL7.dll`;
  the only change is an `os2_reset_fpu()` call in `OSMesaCreateContextExt` and
  `OSMesaMakeCurrent`.
* `src/mesa/main/git_sha1.h` is a stub (no git metadata in a source tarball).
* Everything else (`src/mesa`, `src/glu`, `src/glut/glx`, `include/`, `docs/`) is the
  stock `MesaLib-7.11.2` + `MesaGLUT-7.11.2` content.

## Licences

* **Mesa** and its GLU/GL headers: MIT licence, see `docs/license.html` and `COPYING`.
* **SGI GLU** (`src/glu/sgi`): SGI Free Software License B (MIT-style), headers in
  each file.
* **GLUT** (`src/glut/glx` portable parts, `include/GL/glut.h`): Mark J. Kilgard's
  GLUT licence (free use and redistribution with the copyright notice); see the
  file headers.
* **OS/2 port code** (`src/mesa/drivers/os2`, `src/glut/os2`, makefiles, scripts):
  Copyright (c) 2026 Martin Iturbide (OS2World), released under the MIT licence
  (the same licence as Mesa).
* **Demos:** `glutcube` and `shapes`/`texture` are new code, Copyright (c) 2026
  Martin Iturbide (OS2World), under the MIT licence.
  `gears` is a rewrite of Brian Paul's classic "gears" demo (originally from the Mesa
  demo set); credit and licence follow the original.

## Packaging a release

A release has two zips (names carry the port version):

| Package | Contents |
|---|---|
| `Mesa-7.11.2-os2-1.1-bin.zip`  | `dll/` (three DLLs), `lib/*_imp.a` (import libraries), `include/GL/` (gl.h, glu.h, glut.h, glext.h ...), `demos/` (exes), README |
| `Mesa-7.11.2-os2-1.1-src.zip`  | the cleaned source tree: no object files, no logs, no binaries; builds with `build_dlls.cmd` |

Before packaging, run a clean rebuild from the unpacked source zip
(`build_dlls.cmd`, then `demos\build_demos.cmd`) to prove it needs nothing that was
left lying around.
