package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.media.MediaPlayer;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.NumberPicker;



public class MainActivity extends AppCompatActivity {
    MediaPlayer pianoMusic;
    NumberPicker possibilities;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

            possibilities= (NumberPicker) findViewById(R.id.numberPicker);

        String[] possibilitiesStrings ={
                "Android",
                "Checklist text-input field",
                "Coursera",
                "Supelec"
        };
        possibilities.setDisplayedValues(possibilitiesStrings);
        possibilities.setMinValue(0);
        possibilities.setMaxValue(possibilitiesStrings.length-1);
    }

    public void navigate(View view) {
        int choice=possibilities.getValue();
    }
    public void sendMessage(View view){
        String message=((EditText) (findViewById(R.id.editText_message))).getText().toString();
        Uri destination = Uri.parse("smsto: 5556");
        Intent smsIntent= new Intent(Intent.ACTION_SENDTO, destination);
        smsIntent.putExtra("sms_body",message);
        startActivity(smsIntent);

    }
    public void playMusic(View view){
      pianoMusic.start();
      pianoMusic = MediaPlayer.create(this, R.raw.pianoMusic);
    }
    public void pauseMusic(View view){
     if(pianoMusic.isPlaying())
         pianoMusic.pause();
    }
}
