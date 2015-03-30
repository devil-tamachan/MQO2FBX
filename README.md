# MQO2FBX
Metasequoia4 (.mqo, .mqx) to .fbx

[Winインストーラー](https://github.com/devil-tamachan/MQO2FBX/releases/download/1.0.0/MQO2FBX-1.0.0.exe)

使い方：
 - メタセコ４で出力した.mqoを当ソフトへドロップ

注釈：
 - メタセコ４標準搭載されているHumanoidのボーンだとUnityに読み込めません。
  * hipをルートボーンにして足の関節をhipからぶら下げてください。
  * Handボーンを追加してください
 - ルートボーンが２個以上だとBlenderで読み込めません
 - UVは出力されます
 - スムーズ、ミラーは出力されません。先にフリーズしておいてください
 - テクスチャ画像は出力されません。
 - マテリアルも結構いい加減な出力なのでテクスチャと共に手動で設定してください
 - メタセコ３で出力した.mqoには対応していません
 
謝辞:
 - [FBX SDK](http://www.autodesk.com/products/fbx/overview)
 - [re2c](http://re2c.org/)
 - [lemon parser](http://www.hwaci.com/sw/lemon/)
 - [tinyxml2](https://github.com/leethomason/tinyxml2)