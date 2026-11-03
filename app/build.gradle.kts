plugins {
    id("com.android.application")
}

android {
    namespace = "com.enjoyers"
    compileSdk = 34
    ndkVersion = "26.1.10909125"

    defaultConfig {
        applicationId = "com.enjoyers"
        minSdk = 24
        targetSdk = 34
        versionCode = 1
        versionName = "3.2"
        ndk {
            abiFilters += listOf("arm64-v8a")
        }
    }

    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_17
        targetCompatibility = JavaVersion.VERSION_17
    }

    buildTypes {
        release {
            isMinifyEnabled = false
        }
        debug {
            isMinifyEnabled = false
            isDebuggable = true
        }
    }

    // NDK rebuild optional; prebuilt librizeyt.so in jniLibs is used for CI stability.
    // externalNativeBuild {
    //     ndkBuild {
    //         path = file("src/main/jni/Android.mk")
    //     }
    // }

    packaging {
        jniLibs {
            useLegacyPackaging = true
        }
    }
}

dependencies {
    // Standalone launcher shell; mod logic is in librizeyt.so
}
