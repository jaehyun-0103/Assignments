package com.example.project10_2


import android.os.Bundle
import android.widget.Button
import android.widget.ImageView
import android.widget.RatingBar
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class ResultActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_result)

        title = "투표 결과"

        // 앞 화면에서 보낸 투표 결과 값을 받음
        var intent = intent
        var voteResult = intent.getIntArrayExtra("VoteCount")
        var imageName = intent.getStringArrayExtra("ImageName")?: emptyArray()
        // 9개의 TextView, RatingBar 객체배열
        var tv = arrayOfNulls<TextView>(imageName.size)
        var rbar = arrayOfNulls<RatingBar>(imageName.size)
        // 9개의 TextView, RatingBar ID 배열
        var tvID = arrayOf(R.id.tv1, R.id.tv2, R.id.tv3, R.id.tv4,
            R.id.tv5, R.id.tv6, R.id.tv7, R.id.tv8, R.id.tv9)
        var rbarID = arrayOf(R.id.rbar1, R.id.rbar2, R.id.rbar3, R.id.rbar4,
            R.id.rbar5, R.id.rbar6, R.id.rbar7, R.id.rbar8, R.id.rbar9)

        // 추가한 코드 //
        // 이미지 파일의 id를 저장할 배열
        val imageFileId = arrayOf(R.drawable.pic1, R.drawable.pic2, R.drawable.pic3, R.drawable.pic4,
            R.drawable.pic5, R.drawable.pic6, R.drawable.pic7, R.drawable.pic8, R.drawable.pic9)
        // 득표수가 가장 큰 사진의 배열의 인덱스 번호를 저장
        var max_pic = -1
        var imgName = findViewById<TextView>(R.id.imgName)
        var vic = findViewById<ImageView>(R.id.vic)

        // TextView, RatingBar 개체 찾기
        for (i in voteResult!!.indices) {
            tv[i] = findViewById<TextView>(tvID[i])
            rbar[i] = findViewById<RatingBar>(rbarID[i])
        }

        // 각 TextVeiw 및 RatingBar에 넘겨 받은 값을 반영
        for (i in voteResult.indices) {
            tv[i]!!.setText(imageName[i])
            rbar[i]!!.setRating(voteResult[i].toFloat())
        }

        // 추가한 코드 //
        // 득표수가 가장 큰 사진을 찾고, 그 사진의 인덱스 번호를 통해 사진 이름과 사진을 출력
        for(i in voteResult.indices) {
            if (max_pic < voteResult[i]) {
                max_pic = i
            }
        }
        imgName.text = imageName[max_pic]
        vic.setImageResource(imageFileId[max_pic])

        var btnReturn = findViewById<Button>(R.id.btnReturn)
        btnReturn.setOnClickListener {
            finish()
        }

    }
}