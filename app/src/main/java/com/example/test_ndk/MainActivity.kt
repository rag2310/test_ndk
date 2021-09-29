package com.example.test_ndk

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import com.example.test_ndk.db.AppDatabase
import com.example.test_ndk.model.User
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.coroutineScope
import kotlinx.coroutines.launch

class MainActivity : AppCompatActivity() {

    init {
        System.loadLibrary("native-lib")
    }

    private external fun helloWorld(): String
    private external fun sum(x: Int, y: Int): Int
    private external fun sub(x: Int, y: Int): Int
    private external fun mult(x: Int, y: Int): Int
    private external fun div(x: Int, y: Int): Int
    private external fun initDb(path: String): Int
    lateinit var firstEt: EditText
    lateinit var secondEt: EditText

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val helloWorldTv: TextView = findViewById(R.id.hello)
        val resultTv: TextView = findViewById(R.id.result_tv)
        firstEt = findViewById(R.id.first_number_et)
        secondEt = findViewById(R.id.second_number_et)
        val sumBtn: Button = findViewById(R.id.sum_btn)
        val subBtn: Button = findViewById(R.id.sub_btn)
        val multBtn: Button = findViewById(R.id.mult_btn)
        val divBtn: Button = findViewById(R.id.div_btn)
        helloWorldTv.text = helloWorld()

        /*GlobalScope.launch {

        }*/

        val pathDb = applicationContext.getDatabasePath("test")
        println(pathDb.path)
        initDb(pathDb.path)


        var result: Int = 0

        sumBtn.setOnClickListener {
            val (x, y) = getXAndY()
            result = sum(x, y)


            firstEt.setText("")
            secondEt.setText("")
            resultTv.text = result.toString()
        }

        subBtn.setOnClickListener {
            val (x, y) = getXAndY()
            result = sub(x, y)


            firstEt.setText("")
            secondEt.setText("")
            resultTv.text = result.toString()
        }

        multBtn.setOnClickListener {
            val (x, y) = getXAndY()
            result = mult(x, y)


            firstEt.setText("")
            secondEt.setText("")
            resultTv.text = result.toString()
        }

        divBtn.setOnClickListener {
            val (x, y) = getXAndY()
            result = div(x, y)


            firstEt.setText("")
            secondEt.setText("")
            resultTv.text = result.toString()
        }
    }

    private suspend fun createDatabase() {

        /*coroutineScope {
            launch {
                val appDatabase: AppDatabase = AppDatabase.getDatabase(applicationContext)
                appDatabase.let {
                    val user: User = User(
                        name = "Rodolfo"
                    )
                    it.userDao().insertAll(user)
                }
            }
        }*/
        /*runBlocking {
            launch {
                val appDatabase: AppDatabase = AppDatabase.getDatabase(applicationContext)
                appDatabase.let {
                    val user: User = User(
                        name = "Rodolfo"
                    )
                    it.userDao().insertAll(user)
                }
            }
        }*/
    }

    fun getXAndY(): Pair<Int, Int> {
        val x: Int = firstEt.text.toString().toInt()
        val y: Int = secondEt.text.toString().toInt()
        return Pair(x, y);
    }
}