package Ptrace;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;

public class DebugActivity extends Activity {
    String[] errMessage;
    String[] exceptionType;

    /* access modifiers changed from: protected */
    @Override
    public void onCreate(Bundle bundle) {
        AlertDialog.Builder builder;
        DialogInterface.OnClickListener onClickListener;
        StringBuffer stringBuffer;
        super.onCreate(bundle);
        Intent intent = getIntent();
        Object obj = "";
        String str = "";
        if (intent != null) {
            String stringExtra = intent.getStringExtra("error");
            String[] split = stringExtra.split("\n");
            int i = 0;
            while (true) {
                try {
                    if (i >= this.exceptionType.length) {
                        break;
                    } else if (split[0].contains(this.exceptionType[i])) {
                        String str2 = this.errMessage[i];
                        int indexOf = split[0].indexOf(this.exceptionType[i]) + this.exceptionType[i].length();
                        new StringBuffer();
                      //  str = stringBuffer.append(str2).append(split[0].substring(indexOf, split[0].length())).toString();
                        break;
                    } else {
                        i++;
                    }
                } catch (Exception e) {
                    Exception exc = e;
                }
            }
            if (str.isEmpty()) {
                str = stringExtra;
            }
        }
        new AlertDialog.Builder(this);
        
    }

    public DebugActivity() {
        String[] strArr = new String[5];
        strArr[0] = "StringIndexOutOfBoundsException";
        String[] strArr2 = strArr;
        strArr2[1] = "IndexOutOfBoundsException";
        String[] strArr3 = strArr2;
        strArr3[2] = "ArithmeticException";
        String[] strArr4 = strArr3;
        strArr4[3] = "NumberFormatException";
        String[] strArr5 = strArr4;
        strArr5[4] = "ActivityNotFoundException";
        this.exceptionType = strArr5;
        String[] strArr6 = new String[5];
        strArr6[0] = "Invalid string operation\n";
        String[] strArr7 = strArr6;
        strArr7[1] = "Invalid list operation\n";
        String[] strArr8 = strArr7;
        strArr8[2] = "Invalid arithmetical operation\n";
        String[] strArr9 = strArr8;
        strArr9[3] = "Invalid toNumber block operation\n";
        String[] strArr10 = strArr9;
        strArr10[4] = "Invalid intent operation";
        this.errMessage = strArr10;
    }
}
