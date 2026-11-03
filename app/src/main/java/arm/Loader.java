package arm;

public class Loader {
    static {
        System.loadLibrary("VvipEnjoyers");
    }

    public static native void registerNativesForClass(int i);
}
