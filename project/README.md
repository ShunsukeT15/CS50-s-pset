# Joy Trip!
#### Video Demo:　https://youtu.be/yfxasXISR18
#### Description:
I created this "Joy Trip!" As a convenient application for travel.
The reason I wanted to create it was because there are many useful tools for travel in the world, but their functions are scattered and I found it useful to have a cohesive one.
Also, I thought that I could enjoy it by keeping a record of my trip and registering my next trip.
The functions implemented this time include login function (/.login.html), inventory management (/pack.html), schedule management (/sche.html), memo function (/memo.html), and dice function (/random. html) and bulletin board function (/chat.html).
Regarding the login function, it is not perfect as a user information identification function because the implementation of SQL and python was not successful.
Please note that the video is based on the assumption that you have successfully logged in.
Regarding the inventory management function, write your belongings in the text box and press the add button, and the entered text will be displayed below.
It will be displayed together with the check box, so add the belongings necessary for the trip by the day before, and make effective use of the check box to prepare for the lost item on the day.
Regarding the schedule function, you can add a schedule for each hour in each schedule.
You can increase the number of fill forms with the add button, but the delete button still doesn't work. It will be implemented in the future.
I think that many trips last for several days, so I feel that it is necessary to implement a function that can add this schedule table in its entirety and increase the number of days that can be applied.
Regarding the memo function, you can register destinations, accommodations, websites you want to visit while you are on the move, etc. together with the URL.
Enter the name of the destination etc. in the upper form, enter the URL in the lower form, click the "Write" button to display the name of the destination in bullet points below, and click the name to link to the entered URL Is displayed.
I find this feature surprisingly useful.
Regarding the dice function, enter the text that will be applied when each number when rolling the dice appears in the text form next to the numbers 1 to 6 below,
Then roll the dice. It may not be necessary for many people, but it can be used when you are uncertain about your next destination or activity.
In the video, I gave an example of which type of dinner to choose from seafood, Japanese food, Western food, and Chinese food.
I wasn't able to implement it satisfactorily this time, but I think it would be better if we could add functions such as coloring the numbers below the same numbers as the numbers rolled out and the corresponding text forms.
As for the bulletin board, PHP could not be used, so I only created the form, so the function is incomplete.
I would like to list the extensions of this application that I have come up with as ideas but could not implement by myself.
Countdown display until the next scheduled travel date,
A function that changes the in-app background to an image you registered, such as a photo of your destination or a photo with a member, on the day of your trip.
Cooperation with a map showing directions to the destination and a navigation system,
Album / diary function that can save photos from travel, etc.
Etc. In addition, I think that it will evolve into a more convenient site by implementing other tools that are considered to be useful for travel.


日本語：
私は、旅行に便利なアプリケーションとして、今回の「Joy Trip!」を作成しました。
作成したいと思った理由として、旅行に便利なツールは世の中にたくさんあるものの、それらの機能はバラバラに存在しており、まとまったものがあったら便利だと感じたからです。
また、自分の旅行の記録を残しておくことで思い出となり、次回の旅行を登録することで楽しみを感じる事もできると思いました。
今回実装した機能としては、ログイン機能（/.login.html )、持ち物管理（/pack.html)、スケジュール管理(/sche.html)、メモ機能(/memo.html)、サイコロ機能（/random.html)、掲示板機能(/chat.html)の5つです。
ログイン機能に関しては、SQLやpythonの実装がうまくできなかったため、ユーザー情報識別の機能として完ぺきではありません。
動画ではログインがうまくできたと仮定して進めておりますのでご了承ください。
持ち物管理機能に関して、テキストボックスに持ち物を書き込み追加ボタンを押すことで、記入したテキストが下に表示されます。
チェックボックスとともに表示されるので、前日までに旅行に必要な持ち物を追加しておき、当日になったらチェックボックスを有効活用して忘れ物の内容に準備しましょう。
スケジュール機能に関して、各日程の中での時間ごとスケジュールを追加できます。
追加ボタンで記入フォームの数を増やすことができますが、削除ボタンは未だ機能しません。今後実装予定です。
旅行は数日にわたるものが多いと思うので、このスケジュール表を丸ごと追加できる機能を実装し、適用できる日数を増やす必要があると感じています。
メモ機能に関して、目的地や宿泊施設、移動中に閲覧したいウェブサイトなどをURLとともに登録できます。
上のフォームに目的地などの名前、下のフォームにURLを記入して、「書き込む」ボタンを押すと下に箇条書きで目的地の名前が表示され、名前をクリックすると記入したURLのリンク先が表示されます。
この機能は意外と便利だと感じています。
サイコロ機能に関して、下の1~6の数字の横のテキストフォームにサイコロを振った際の各数字が出たときに適用されるテキストを入力して、
そのあとでサイコロを振ります。多くの人には必要ないかもしれませんが、次の行き先や、アクティビティなど選択肢に迷ったときに活用できます。
動画の中では夕食の種類を海鮮、和食、洋食、中華の中からどれにするかという例で行いました。
今回は満足する実装ができませんでしたが、サイコロを振って出た数字と同じ下の数字やそれに対応したテキストフォームに色がつくなどの機能を追加できたらよりよくなると思います。
掲示板に関しても、PHPの活用ができなかったため、フォームの作成のみ行ったので機能としては未完成です。
このアプリケーションの拡張機能として、アイディアとしては挙がったものの、自分ひとりの力では実装できなかったものを以下に挙げたいと思います。
次回の旅行予定日までのカウントダウン表示、
旅行当日にアプリ内背景が、目的地の写真やメンバーとの写真など自分が登録した画像に変化する機能、
目的地までの道順を示す地図やナビゲーションシステムとの連携、
旅行での写真などを保存できるアルバム・日記機能、
などです。また、他にも旅行に便利だと思われるツールを実装することで、より便利なサイトに進化すると思います。