package com.example.project10_1

import android.os.Bundle
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity

class SecondActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_second)

        title="Second Activity"

        var btnReturn = findViewById<Button>(R.id.btnReturn)
        btnReturn.setOnClickListener{
            finish()
        }
    }
}