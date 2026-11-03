package Ptrace;

import android.app.AlarmManager;
import android.app.Application;
import android.app.PendingIntent;
import android.content.Intent;
import android.os.Process;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.io.Writer;
import java.lang.Thread;

public class Applications extends Application {
	
	public Thread.UncaughtExceptionHandler uncaughtExceptionHandler;
	public PrintWriter printWriter;
	public Writer writer;
	public Intent intent;
	
    @Override
    public void onCreate() {
		this.uncaughtExceptionHandler = Thread.getDefaultUncaughtExceptionHandler();
        new Thread.UncaughtExceptionHandler() {
			
            @Override
            public void uncaughtException(Thread thread, Throwable th) {
                Throwable th2;
                Thread thread2 = thread;
                Throwable th3 = th;
                
                try {
                    Intent intent = new Intent(Applications.this.getApplicationContext(), Class.forName("Ptrace.DebugActivity"));
                    ((AlarmManager) Applications.this.getSystemService("alarm")).set(2, (long) 1000, PendingIntent.getActivity(Applications.this.getApplicationContext(), 11111, intent, 1073741824));
                    Process.killProcess(Process.myPid());
                    System.exit(2);
                    Applications.this.uncaughtExceptionHandler.uncaughtException(thread2, th3);
                } catch (ClassNotFoundException e) {
                    ClassNotFoundException classNotFoundException = e;
                    
                    new NoClassDefFoundError(classNotFoundException.getMessage());
                    
                }
            }
        };
        Thread.setDefaultUncaughtExceptionHandler(uncaughtExceptionHandler);
        super.onCreate();
    }
	
    /* access modifiers changed from: private */
    public String getStackTrace(Throwable th) {
        
        new StringWriter();
        Writer writer2 = writer;
        new PrintWriter(writer2);
        Throwable th2 = th;
        while (true) {
            Throwable th3 = th2;
            if (th3 == null) {
                String writer3 = writer2.toString();
                printWriter.close();
                return writer3;
            }
            th3.printStackTrace(printWriter);
            th2 = th3.getCause();
        }
    }

    public Applications() {
    }
}
