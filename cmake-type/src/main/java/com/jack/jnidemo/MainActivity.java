package com.jack.jnidemo;

import android.content.Context;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    private static String TAG = "MainActivity";
    private static Context appContext;

    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        appContext = getApplicationContext();
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI("我是MainActivity,tell me why!"));

        findViewById(R.id.b_jni_c).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                callJNIConvertJavaMethod();
            }
        });
    }

    /**
     * 供jni调用的Java方法
     *
     * @param toast
     */
    public static void methodCalledByJni(String toast) {
        Toast.makeText(appContext, toast, Toast.LENGTH_SHORT).show();
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI(String hiJni);

    // 定义调用本地方法, 好让本地方法回调java中的方法
    public native void callJNIConvertJavaMethod();
}
