#include <Arduino.h>
#include "timer.hpp"
// // ピアノのキーに対応する周波数
// int frequencies[] = {
//   262, 294, 330, 349, 392, 440, 494, 523, // ド、レ、ミ、ファ、ソ、ラ、シ、ド
//   587, 659, 698, 784, 880, 988, 1047, 1175 // レ、ミ、ファ、ソ、ラ、シ、ド、レ
// };

// // ピアノのキーに対応するピン
// int keys[] = {
//   2, 3, 4, 5, 6, 7, 8, 9, // ピン2〜9を使用
//   A0, A1, A2, A3, A4, A5, 10, 11 // ピンA0〜A5と10, 11を使用
// };

// int speakerPin = 12; // スピーカーのピン

// void setup() {
//   // スピーカーのピンを出力に設定
//   pinMode(speakerPin, OUTPUT);
  
//   // ピンを入力に設定
//   for (int i = 0; i < 16; i++) {
//     pinMode(keys[i], INPUT_PULLUP);
//   }
// }

// void loop() {
//   int compositeFrequency = 0; // 複合音の周波数
  
//   // 全てのキーの状態をチェックし、押されているキーに対応する周波数の合計を計算する
//   for (int i = 0; i < 16; i++) {
//     if (digitalRead(keys[i]) == LOW) {
//       compositeFrequency += frequencies[i];
//     }
//   }
  
//   // 複合音を再生する
//   if (compositeFrequency > 0) {
//     tone(speakerPin, compositeFrequency);
//   } else {
//     noTone(speakerPin);
//   }
// }
// ピアノのキーに対応するピン
int keys[] = {
  2,   // ピン2: ド
  3,   // ピン3: ド# (黒鍵盤)
  4,   // ピン4: レ
  5,   // ピン5: レ# (黒鍵盤)
  6,   // ピン6: ミ
  7,   // ピン7: ファ
  8,   // ピン8: ファ# (黒鍵盤)
  9,   // ピン9: ソ
  10,  // ピン10: ソ# (黒鍵盤)
  11,  // ピン11: ラ
  A0,  // ピン12: ラ# (黒鍵盤)
  A1,  // ピンA0: シ
  A2   // ピンA1: ド
};
int frequencies[] = {
    262, // ド
    277, // ド# (黒鍵盤)
    294, // レ
    311, // レ# (黒鍵盤)
    330, // ミ
    349, // ファ
    370, // ファ# (黒鍵盤)
    392, // ソ
    415, // ソ# (黒鍵盤)
    440, // ラ
    466, // ラ# (黒鍵盤)
    494, // シ
    523  // ド
  };
int speakerPin = 12; // スピーカーのピン
int volum = 0;
int nowSound = 0;
IntervalTimer timeUp(100);
void setup() {
  // スピーカーのピンを出力に設定
  pinMode(speakerPin, OUTPUT);
  
  // ピンを入力に設定
  for (int i = 0; i < 13; i++) {
    pinMode(keys[i], INPUT_PULLUP);
  }
}

void loop() {
  // ピアノのキーが押されたら音を再生する
  for (int i = 0; i < 13; i++) {
    if (digitalRead(keys[i]) == LOW) {
      // 弦楽器のような音を再生する
      // nowSound = frequencies[i];
      volum = 127;
      tone(speakerPin, frequencies[i]);
      timeUp.init();
      // playStringInstrumentSound(i);
      // delay(500); // ピアノのキーが押された後のディレイ
    }
    if(timeUp.isWait()){
      noTone(speakerPin);
    }
  }
}

void playStringInstrumentSound(int keyIndex) {
  // ピアノのキーに対応する周波数
  

  // 指定された周波数の音を再生する
  tone(speakerPin, frequencies[keyIndex]);
}
