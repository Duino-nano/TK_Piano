#include <Arduino.h>

#include "timer.hpp"

// ピアノのキーに対応するピン
const int keys[] = {
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

// ピアノのキーに対応する周波数
const int frequencies[] = {
    262,  // ド
    277,  // ド# (黒鍵盤)
    294,  // レ
    311,  // レ# (黒鍵盤)
    330,  // ミ
    349,  // ファ
    370,  // ファ# (黒鍵盤)
    392,  // ソ
    415,  // ソ# (黒鍵盤)
    440,  // ラ
    466,  // ラ# (黒鍵盤)
    494,  // シ
    523   // ド
};

int speakerPin = 12;        // スピーカーのピン
IntervalTimer timeUp(100);  // 100msのタイマーを設定

// セットアップ関数　初期化時に一度だけ実行される
void setup() {
  // スピーカーのピンを出力に設定
  pinMode(speakerPin, OUTPUT);

  // keysに登録したピンを入力に順番に設定
  for (int i = 0; i < 13; i++) {
    pinMode(keys[i], INPUT_PULLUP);
  }
}

// ループ関数　初期化後に繰り返し実行される
void loop() {
  // 順番にキーをチェックして、押されていたら音を鳴らす
  for (int i = 0; i < 13; i++) {
    if (digitalRead(keys[i]) == LOW) {   // キーが押されているかチェック
      tone(speakerPin, frequencies[i]);  // キーと一致した音を鳴らす
      timeUp.init();                     // タイマー初期化
    }
    if (timeUp.isWait()) {  // 100msタイマー経過確認
      noTone(speakerPin);   // 音を止める
    }
  }
}
