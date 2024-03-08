package com.example.calculator2

import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        //멤버 변수로 선언
        lateinit var edit1 : EditText
        lateinit var edit2 : EditText
        lateinit var btnAdd : Button
        lateinit var btnSub : Button
        lateinit var btnMul : Button
        lateinit var btnDiv : Button
        lateinit var textResult : TextView
        lateinit var num1 : String
        lateinit var num2 : String
        var result : Int? = null

        // 10개 숫자 버튼 배열
        var numButtons  = ArrayList<Button>(10)
        // 10개 숫자 버튼의 id 값 배열
        var numBtnIDs = arrayOf(R.id.BtnNum0, R.id.BtnNum1, R.id.BtnNum2, R.id.BtnNum3, R.id.BtnNum4, R.id.BtnNum5, R.id.BtnNum6, R.id.BtnNum7, R.id.BtnNum8, R.id.BtnNum9)

        for (i in 0..9 step 1)
            numButtons.add(findViewById<Button>(numBtnIDs[i]))

        //onCreate() 내부에 작성
        title = "계산기"
        edit1 = findViewById<EditText>(R.id.Edit1)
        edit2 = findViewById<EditText>(R.id.Edit2)
        btnAdd = findViewById<Button>(R.id.BtnAdd)
        btnSub = findViewById<Button>(R.id.BtnSub)
        btnMul = findViewById<Button>(R.id.BtnMul)
        btnDiv = findViewById<Button>(R.id.BtnDiv)
        textResult = findViewById<TextView>(R.id.TextResult)

        // 숫자 버튼 10개에 대해서 클릭이벤트 처리
        for (i in 0..numBtnIDs.size-1 step 1){
            numButtons[i].setOnClickListener {
                // 포커스가 되어 있는 에디트텍스트에 숫자 추가
                if (edit1.isFocused == true) {
                    num1 = edit1.text.toString() + numButtons[i].getText().toString()
                    edit1.setText(num1)
                } else if (edit2.isFocused == true) {
                    num2 = edit2.text.toString() + numButtons[i].getText().toString()
                    edit2.setText(num2)
                } else {
                    Toast.makeText(applicationContext, "먼저 에디트텍스트를 선택하세요", Toast.LENGTH_SHORT).show()
                }
            }
        }

        btnAdd.setOnTouchListener { view, motionEvent ->
            num1 = edit1.text.toString()
            num2 = edit2.text.toString()
            result = Integer.parseInt(num1) + Integer.parseInt(num2)
            textResult.text = result.toString()
            false
        }

        btnSub.setOnTouchListener { view, motionEvent ->
            num1 = edit1.text.toString()
            num2 = edit2.text.toString()
            result = Integer.parseInt(num1) - Integer.parseInt(num2)
            textResult.text = result.toString()
            false
        }

        btnMul.setOnTouchListener { view, motionEvent ->
            num1 = edit1.text.toString()
            num2 = edit2.text.toString()
            result = Integer.parseInt(num1) * Integer.parseInt(num2)
            textResult.text = result.toString()
            false
        }

        btnDiv.setOnTouchListener { view, motionEvent ->
            num1 = edit1.text.toString()
            num2 = edit2.text.toString()
            if (num2 == "0") {
                Toast.makeText(this, "0으로 나눌 수 없음", Toast.LENGTH_SHORT).show()
                textResult.text = "0"
            }
            else {
                result = Integer.parseInt(num1) / Integer.parseInt(num2)
                textResult.text = result.toString()
            }
            false
        }
    }
}