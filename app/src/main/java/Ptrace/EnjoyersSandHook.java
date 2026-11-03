package Ptrace;

import android.content.ContentProvider;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.net.Uri;
import arm.Loader;
import java.util.concurrent.ScheduledExecutorService;

public class EnjoyersSandHook extends ContentProvider implements Runnable {
    private static int[] d;
    private static int[] j;
    private final ScheduledExecutorService scheduler = b(1);
    Context scontext;

    static {
        Loader.registerNativesForClass(0);
        native_special_clinit0();
    }

    public static native ScheduledExecutorService b(int i);

    public static native ScheduledExecutorService c(EnjoyersSandHook enjoyersSandHook);

    public static native void e(String str);

    private static native /* synthetic */ void native_special_clinit0();

    @Override
    public native int delete(Uri uri, String str, String[] strArr);

   
    @Override
    public native String getType(Uri uri);

    
    @Override
    public native Uri insert(Uri uri, ContentValues contentValues);

    @Override
    public native boolean onCreate();

    
    @Override
    public native Cursor query(Uri uri, String[] strArr, String str, String[] strArr2, String str2);

    @Override
    public native void run();

    @Override
    public native int update(Uri uri, ContentValues contentValues, String str, String[] strArr);
}

