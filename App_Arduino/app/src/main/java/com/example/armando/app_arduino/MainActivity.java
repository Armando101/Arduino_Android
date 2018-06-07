package com.example.armando.app_arduino;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ImageButton;
import android.view.View;
import android.view.View.OnClickListener;


public class MainActivity extends AppCompatActivity implements OnClickListener {

    ImageButton bluetooth, automatic, information;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Iniciar();
    }

    public void Iniciar() {
        bluetooth=(ImageButton) findViewById(R.id.blue);
        automatic=(ImageButton) findViewById(R.id.auto);
        information=(ImageButton) findViewById(R.id.info);

        bluetooth.setOnClickListener(this);
        automatic.setOnClickListener(this);
        information.setOnClickListener(this);
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.blue:
                Intent i = new Intent(this, BlueActivity.class);
                startActivity(i);
                break;
            case R.id.auto:
                Intent j = new Intent(this, Autmatic_Activity.class);
                startActivity(j);
                break;
            case R.id.info:
                Intent k = new Intent(this, Data_Activity.class);
                startActivity(k);
                break;
        }
    }
}
