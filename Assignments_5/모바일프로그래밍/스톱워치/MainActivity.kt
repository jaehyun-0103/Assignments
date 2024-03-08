package com.example.stopwatch

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.LinearLayout
import android.widget.TextView
import com.google.android.material.floatingactionbutton.FloatingActionButton
import java.util.*
import kotlin.concurrent.timer

class MainActivity : AppCompatActivity() {
    private var time = 0 // 시간을 계산할 변수를 0으로 초기화
    private var timerTask: Timer? = null    // Timer 타입의 timerTask를 null을 허용하도록 선언
    private var isRunning = false

    private var lap = 1 // 추가되는 랩 타임 번호

    private lateinit var startFab : FloatingActionButton
    private lateinit var resetFab : FloatingActionButton
    private lateinit var secTextView : TextView
    private lateinit var milliTextView : TextView
    private lateinit var lapButton : Button
    private lateinit var lapLayout : LinearLayout

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        startFab = findViewById<FloatingActionButton>(R.id.startFab)
        resetFab = findViewById<FloatingActionButton>(R.id.resetFab)
        secTextView = findViewById<TextView>(R.id.secTextView)
        milliTextView = findViewById<TextView>(R.id.milliTextView)
        lapButton = findViewById<Button>(R.id.lapButton)
        lapLayout = findViewById<LinearLayout>(R.id.lapLayout)

        // onCreate() 메소드 내부에 시작과 일시정지 이벤트를 구현
        startFab.setOnClickListener {
            isRunning = !isRunning

            if (isRunning)
                start()
            else
                pause()
        }

        // 랩 타임 버튼에 이벤트를 연결하도록 onCreare() 메소드 내부에 구현
        lapButton.setOnClickListener {
            recordLapTime()
        }

        // 초기화 버튼에 reset() 연결
        resetFab.setOnClickListener {
            reset()
        }
    }

    // MainActivity.kt 파일에 타이머를 시작할 때 호출할 start() 메서드를 작성
    private fun start() {
        startFab.setImageResource(R.drawable.ic_pause_black_24dp) // 일시정지 이미지로 변경

        timerTask = timer(period = 10) {// 0.01초마다 작업하는 timer
            time++ // time 변수를 1씩 증가
            val sec = time / 100
            val milli = time % 100
            runOnUiThread { // UI 갱신
                secTextView.text = "$sec"
                milliTextView.text = "$milli"
            }
        }
    }

    // MainActivity.kt 파일에 일시정지 메서드인 pause() 메서드를 작성
    private fun pause() {
        startFab.setImageResource(R.drawable.ic_play_arrow_black_24dp) // 시작 이미지로 교체

        timerTask?.cancel(); // 타이머 취소
    }

    // 랩 타임을 기록하고 화면에 표시하는 메서드인 recordLapTime() 메서드 작성
    private fun recordLapTime() {
        val lapTime = this.time // 현재 시간 저장
        val textView = TextView(this) // 텍스트 뷰 생성
        textView.text = "$lap LAB : ${lapTime / 100}.${lapTime % 100}" // 1 LAB 5.35처럼 출력되도록 설정

        // 맨 위에 랩타임 추가
        lapLayout.addView(textView,0) // 리니어 레이아웃에 랩 타임 추가
        lap++ // 랩 타임 번호 증가
    }

    // 타이머를 초기화하는 reset() 메서드를 구현
    private fun reset() {
        timerTask?.cancel() // 실행중인 타이머 취소

        // 모든 변수 초기화 -> 초기화이기 때문에 모든 변수와 화면에 보이는 모든 정보를 초기화
        time = 0
        isRunning = false
        startFab.setImageResource(R.drawable.ic_play_arrow_black_24dp)
        secTextView.text = "0"
        milliTextView.text = "00"

        // 모든 랩타임을 제거
        lapLayout.removeAllViews()
        lap = 1
    }
}