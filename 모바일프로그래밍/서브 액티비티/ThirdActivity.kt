package com.example.project10_1

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button

class ThirdActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_third)

        title="Third Activity"

        var btnReturn = findViewById<Button>(R.id.btnReturn)
        btnReturn.setOnClickListener{
            finish()
        }
    }
}