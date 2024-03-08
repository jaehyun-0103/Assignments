package com.example.project10_1

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.RadioButton

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        title="project10_1"

        var btnNewActivity = findViewById<Button>(R.id.btnNewActivity)
        var rdoSecond = findViewById<RadioButton>(R.id.rdoSecond)
        var rdoThird = findViewById<RadioButton>(R.id.rdoThird)

        btnNewActivity.setOnClickListener{
            if (rdoSecond.isChecked)
                intent = Intent(applicationContext, SecondActivity::class.java)
            else if (rdoThird.isChecked)
                intent = Intent(applicationContext, ThirdActivity::class.java)
            startActivity(intent)
        }
    }
}