# ML Inject terbaru

Legacy **MLBB mod launcher** (`com.enjoyers`) from the terbaru project zip. This is a **main Android application** (`com.android.application`), not a library-only loader.

## Build

```bash
./gradlew assembleDebug
```

CI: **Actions → Build APK** → artifact `ml-inject-terbaru-debug`.

## What this APK is

| Check | Value |
|--------|--------|
| Plugin | `com.android.application` |
| `applicationId` | `com.enjoyers` |
| Launcher | `com.mycompany.myapp.MainActivity` |
| Native mod | `librizeyt.so` (NDK / bundled) |

Inject style in source: copy/hook path disguised as MLBB `libAkSoundEnginerize.so` (see `RIZE.cpp`). **Not** the same as ASTRAL `powerhax-loader` (external `libloader64` + downloaded `libTool.so`).

## Fixes applied for CI

- Manifest → correct `MainActivity` class
- `System.loadLibrary("rizeyt")` (was broken `VM`)
- Gradle 8 + AGP 8.2, arm64-v8a only
- `ImGui` path in `Android.mk` (Linux case)
