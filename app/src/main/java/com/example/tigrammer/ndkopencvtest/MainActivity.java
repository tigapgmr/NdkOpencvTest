package com.example.tigrammer.ndkopencvtest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    public native String stringFromJNI();
    public native int intFromJNI(int num1, int num2);

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("imported-lib");
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());

        TextView tv2 = (TextView) findViewById(R.id.sample_text2);
        tv2.setText("Result : " + intFromJNI(3,4));
    }


}
