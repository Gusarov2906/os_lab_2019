<div class="WordSection1">

**<u><span style="font-size:22.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">Лабораторная работа 2.</span></u>**

_<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Необходимые знания</span>__<span lang="EN-US" style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E;
mso-ansi-language:EN-US">:</span>_

<span style="font-size:16.0pt;line-height:107%;font-family:Symbol;mso-fareast-font-family:
Symbol;mso-bidi-font-family:Symbol;color:#24292E;mso-bidi-font-style:italic"><span style="mso-list:Ignore">·<span style="font:7.0pt &quot;Times New Roman&quot;"></span> </span></span>_<span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Выделение и освобождение памяти в куче Си.</span>_

<span style="font-size:16.0pt;line-height:107%;font-family:Symbol;mso-fareast-font-family:
Symbol;mso-bidi-font-family:Symbol;color:#24292E;mso-bidi-font-style:italic"><span style="mso-list:Ignore">·<span style="font:7.0pt &quot;Times New Roman&quot;"></span> </span></span>_<span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">В чем разница между стеком и кучей (прямо в задании не потребуется, но я спрошу).</span>_

<span style="font-size:16.0pt;line-height:107%;font-family:Symbol;mso-fareast-font-family:
Symbol;mso-bidi-font-family:Symbol;color:#24292E;mso-bidi-font-style:italic"><span style="mso-list:Ignore">·<span style="font:7.0pt &quot;Times New Roman&quot;"></span> </span></span>_<span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Использование аргументов командной строки</span>_

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E"></span>

**<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Стек</span>**

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Стек — это область оперативной памяти, которая создаётся для каждого потока. Он работает в порядке LIFO (<span class="SpellE">Last</span> <span class="SpellE">In</span>, <span class="SpellE">First</span> <span class="SpellE">Out</span><span class="GramE">), <span style="mso-spacerun:yes"></span> то</span> есть последний добавленный в стек кусок памяти будет первым в очереди на вывод из стека. Каждый раз, когда функция объявляет новую переменную, она добавляется в стек, а когда эта переменная пропадает из области видимости (например, когда функция заканчивается), она автоматически удаляется из стека. Когда стековая переменная освобождается, эта область памяти становится доступной для других стековых переменных.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Из-за такой природы стека управление памятью оказывается весьма логичным и простым для выполнения на ЦП; это приводит к высокой скорости, в особенности потому, что время цикла обновления байта стека очень мало, т.е. этот байт скорее всего привязан к кэшу процессора. Тем не менее, у такой строгой формы управления есть и недостатки. Размер стека — это фиксированная величина, и превышение лимита выделенной на стеке памяти приведёт к переполнению стека. Размер задаётся при создании потока, и у каждой переменной есть максимальный размер, зависящий от типа данных. Это позволяет ограничивать размер некоторых переменных (например, целочисленных), и вынуждает заранее объявлять размер более сложных типов данных (например, массивов), поскольку стек не позволит им изменить его. Кроме того, переменные, расположенные на стеке, всегда являются локальными.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">В итоге стек позволяет управлять памятью наиболее эффективным образом — но если вам нужно использовать динамические структуры данных или глобальные переменные, то стоит обратить внимание на кучу.</span>

**<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Куча</span>**

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Куча — это хранилище памяти, также расположенное в ОЗУ, которое допускает динамическое выделение памяти и не работает по принципу стека: это просто склад для ваших переменных. Когда вы выделяете в куче участок памяти для хранения переменной, к ней можно обратиться не только в потоке, но и во всем приложении. Именно так определяются глобальные переменные. По завершении приложения все выделенные участки памяти освобождаются. Размер кучи задаётся при запуске приложения, но, в отличие от стека, он ограничен лишь физически, и это позволяет создавать динамические переменные.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Вы взаимодействуете с кучей посредством ссылок, обычно называемых указателями — это переменные, чьи значения являются адресами других переменных. Создавая указатель, вы указываете на местоположение памяти в куче, что задаёт начальное значение переменной и говорит программе, где получить доступ к этому значению. Из-за динамической природы кучи ЦП не принимает участия в контроле над ней; в языках без сборщика мусора (C, C++) разработчику нужно вручную освобождать участки памяти, которые больше не нужны. Если этого не делать, могут возникнуть утечки и фрагментация памяти, что существенно замедлит работу кучи.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">В сравнении со стеком, куча работает медленнее, поскольку переменные разбросаны по памяти, а не сидят на верхушке стека. Некорректное управление памятью в куче приводит к замедлению её работы; тем не менее, это не уменьшает её важности — если вам нужно работать с динамическими или глобальными переменными, пользуйтесь кучей. Вкратце, стек — это очень быстрое хранилище памяти, работающее по принципу LIFO и управляемое процессором. Но эти преимущества приводят к ограниченному размеру стека и специальному способу получения значений. Для того, чтобы избежать этих ограничений, можно пользоваться кучей — она позволяет создавать динамические и глобальные переменные — но управлять памятью должен либо сборщик мусора, либо сам программист, да и работает куча медленнее.</span>

**<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E"></span>**

**<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Выделение динамической памяти в C</span>**

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E"></span>

<span class="SpellE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">void</span></span> <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">* <span class="SpellE"><span class="GramE">malloc</span></span><span class="GramE">( <span class="SpellE">size</span></span><span class="SpellE">_t</span> <span class="SpellE">sizemem</span> );</span>

_<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Описание</span>_

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Функция <span class="SpellE">malloc</span> выделяет блок памяти, размером <span class="SpellE">sizemem</span> байт, и возвращает указатель на начало блока.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Содержание выделенного блока памяти не инициализируется, оно остается с неопределенными значениями.</span>

_<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Параметры:</span>_

<span class="SpellE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">sizemem</span></span><span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E"></span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Размер выделяемого блока памяти в байтах.</span>

_<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Возвращаемое значение</span>_

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Указатель на выделенный блок памяти. <span class="GramE">Тип данных</span> на который ссылается указатель всегда <span class="SpellE">void</span>*, поэтому это тип данных может быть приведен к желаемому типу данных.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Если функции не удалось выделить требуемый блок памяти, возвращается нулевой указатель.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E"></span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E"></span>

<span lang="EN-US" style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E;
mso-ansi-language:EN-US">void * <span class="SpellE"><span class="GramE">calloc</span></span><span class="GramE">( <span class="SpellE">size</span></span><span class="SpellE">_t</span> number, <span class="SpellE">size_t</span> size );</span>

<span lang="EN-US" style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E;
mso-ansi-language:EN-US"></span>

_<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Описание</span>_

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Функция <span class="SpellE">calloc</span> выделяет блок памяти для массива размером — <span class="SpellE">num</span> элементов, каждый из которых занимает <span style="mso-spacerun:yes"></span> <span class="SpellE">size</span> байт, и инициализирует все свои биты <span class="GramE">в нулями</span>.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">В результате выделяется блок памяти размером <span class="SpellE">number</span> * <span class="SpellE">size</span> байт, причём весь блок заполнен нулями.</span>

_<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Параметры:</span>_

<span class="SpellE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">number</span></span><span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E"></span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Количество элементов массива, под который выделяется память.</span>

<span class="SpellE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">size</span></span><span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E"></span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Размер одного элемента в байтах.</span>

_<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Возвращаемое значение</span>_

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Указатель на выделенный блок памяти. <span class="GramE">Тип данных</span> на который ссылается указатель всегда <span class="SpellE">void</span>*, поэтому это тип данных может быть приведен к желаемому типом данных.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Если функции не удалось выделить требуемый блок памяти, возвращается нулевой указатель.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E"></span>

<span lang="EN-US" style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E;
mso-ansi-language:EN-US">void * <span class="SpellE"><span class="GramE">realloc</span></span><span class="GramE">( void</span> * <span class="SpellE">ptrmem</span>, <span class="SpellE">size_t</span> size );</span>

_<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Описание</span>_

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Функция <span class="SpellE">realloc</span> выполняет перераспределение блоков памяти.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Размер блока памяти, на который ссылается параметр <span class="SpellE">ptrmem</span> изменяется на <span class="SpellE">size</span> байтов. Блок памяти может уменьшаться или увеличиваться в размере.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Эта функция может перемещать блок памяти на новое место, в этом случае функция возвращает указатель на новое место в памяти. Содержание блока памяти сохраняется даже если новый блок имеет меньший размер, чем старый. Отбрасываются только те данные, которые не вместились в новый блок. <span style="mso-spacerun:yes"></span> Если новое значение <span class="SpellE"><span class="GramE">size</span></span><span class="GramE"> <span style="mso-spacerun:yes"></span> больше</span> старого, то содержимое вновь выделенной памяти будет неопределенным.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">В случае, если <span class="SpellE">ptrmem</span> равен NULL, функция ведет себя именно так, как функция <span class="SpellE">malloc</span>, т. е. выделяет память и возвращает указатель на этот участок памяти.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">В случае, если <span class="SpellE">size</span> равен 0, ранее выделенная память будет освобождена, как если бы была вызвана функция <span class="SpellE">free</span>, и возвращается нулевой указатель.</span>

_<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Параметры:</span>_

<span class="SpellE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">ptrmem</span></span><span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E"></span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Указатель на блок ранее выделенной памяти функциями <span class="SpellE">malloc</span>, <span class="SpellE">calloc</span> или <span class="SpellE">realloc</span> для перемещения в новое место. Если этот параметр — NULL, просто выделяется новый блок, и функция возвращает на него указатель.</span>

<span class="SpellE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">size</span></span><span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E"></span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Новый размер, в байтах, выделяемого блока памяти. Если <span class="SpellE">size</span> равно 0, ранее выделенная память <span class="GramE">освобождается</span> и функция возвращает нулевой указатель, <span class="SpellE">ptrmem</span> устанавливается в 0.</span>

_<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Возвращаемое значение</span>_

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Указатель на перераспределенный блок памяти, который может быть либо таким же, как аргумент <span class="SpellE">ptrmem</span> или ссылаться на новое место.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Тип данных возвращаемого значения всегда <span class="SpellE">void</span>*, который может быть приведен к любому другому.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Если функции не удалось выделить требуемый блок памяти, возвращается нулевой указатель, и блок памяти, на который указывает аргумент <span class="SpellE">ptr</span> остается неизменным.</span>

<span class="SpellE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">void</span></span> <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E"><span class="SpellE"><span class="GramE">free</span></span><span class="GramE">( <span class="SpellE">void</span></span> * <span class="SpellE">ptrmem</span> );</span>

_<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Описание</span>_

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Функция <span class="SpellE">free</span> освобождает место в памяти. Блок памяти, ранее выделенный с помощью вызова <span class="SpellE">malloc</span>, <span class="SpellE">calloc</span> или <span class="SpellE">realloc</span> освобождается. То есть освобожденная память может <span class="GramE">дальше <span style="mso-spacerun:yes"></span> использоваться</span> программами или ОС.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Обратите внимание, что эта функция оставляет значение <span class="SpellE">ptr</span> неизменным, следовательно, он по-прежнему указывает на тот же блок памяти, а не на нулевой указатель.</span>

_<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Параметры:</span>_

<span class="SpellE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">ptrmem</span></span><span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E"></span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Указатель на блок памяти, ранее выделенный функциями <span class="SpellE">malloc</span>, <span class="SpellE">calloc</span> или <span class="SpellE">realloc</span>, которую необходимо высвободить. Если в качестве аргумента передается нулевой указатель, никаких действий не происходит.</span>

_<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Возвращаемое значение</span>_

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Функция не имеет возвращаемое значение.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E"></span>

_<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Необходимые знания</span>_

<span style="font-size:16.0pt;line-height:107%;font-family:Symbol;mso-fareast-font-family:
Symbol;mso-bidi-font-family:Symbol;color:#24292E"><span style="mso-list:Ignore">·<span style="font:7.0pt &quot;Times New Roman&quot;"></span> </span></span><span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">Основы работы компилятора: препроцессор, компилятор, линковщик. Их роли и порядок работы.</span>

<span style="font-size:16.0pt;line-height:107%;font-family:Symbol;mso-fareast-font-family:
Symbol;mso-bidi-font-family:Symbol;color:#24292E"><span style="mso-list:Ignore">·<span style="font:7.0pt &quot;Times New Roman&quot;"></span> </span></span><span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">Что такое статическая и динамическая линковка. В чем разница?</span>

<span style="font-size:16.0pt;line-height:107%;font-family:Symbol;mso-fareast-font-family:
Symbol;mso-bidi-font-family:Symbol;color:#24292E"><span style="mso-list:Ignore">·<span style="font:7.0pt &quot;Times New Roman&quot;"></span> </span></span><span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">Опции компилятора: -I, -L, -l, -<span class="SpellE">shared</span>, -o, -с, -<span class="SpellE">fPIC</span></span>

<span style="font-size:16.0pt;line-height:107%;font-family:Symbol;mso-fareast-font-family:
Symbol;mso-bidi-font-family:Symbol;color:#24292E"><span style="mso-list:Ignore">·<span style="font:7.0pt &quot;Times New Roman&quot;"></span> </span></span><span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">Утилита <span class="SpellE">ar</span>.</span>

<span style="font-size:16.0pt;line-height:107%;font-family:Symbol;mso-fareast-font-family:
Symbol;mso-bidi-font-family:Symbol;color:#24292E"><span style="mso-list:Ignore">·<span style="font:7.0pt &quot;Times New Roman&quot;"></span> </span></span><span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">Переменная окружения LD_LIBRARY_PATH</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E"></span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E"></span>

**<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Препроцессор</span>** <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">— это компьютерная программа, принимающая данные на входе и выдающая данные, предназначенные для входа другой программы (например, компилятора).</span>

<span class="SpellE">**<span style="font-size:16.0pt;
line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:
major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;
color:#24292E">Компиля́тор</span>**</span> <span style="font-size:16.0pt;
line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:
major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;
color:#24292E">– это специальная программа, которая переводит текст программы, написанный на языке программирования, в набор машинных кодов.</span>

**<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Компоновщик</span>** <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">(также редактор связей, от англ. <span class="SpellE">link</span> <span class="SpellE">editor</span>, <span class="SpellE">linker</span>) — инструментальная программа, которая производит компоновку («линковку»): принимает на вход один или несколько объектных модулей и собирает по ним исполнимый модуль.</span>

**<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Объектный файл</span>** <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">– файл, содержащий скомпилированный машинный код и дополнительные данные (зависимости, как загружать и запускать и т.д.)</span>

**<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Сборка:</span>**

**<span style="font-size:16.0pt;line-height:107%;mso-bidi-font-family:Calibri;
mso-bidi-theme-font:minor-latin;color:#24292E"><span style="mso-list:Ignore">1.<span style="font:7.0pt &quot;Times New Roman&quot;"></span> </span></span>**<span class="SpellE">**<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Препроцессинг</span>**</span>**<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E"></span>**

**<span lang="EN-US" style="font-size:16.0pt;
line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:
major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;
color:#24292E;mso-ansi-language:EN-US">C</span>****<span style="font-size:
16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:
major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;
color:#24292E">/</span>****<span lang="EN-US" style="font-size:16.0pt;
line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:
major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;
color:#24292E;mso-ansi-language:EN-US">C</span>****<span style="font-size:
16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:
major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;
color:#24292E">++ с директивами препроцессора -> Чистый код</span>**

**<span style="font-size:16.0pt;line-height:107%;mso-bidi-font-family:Calibri;
mso-bidi-theme-font:minor-latin;color:#24292E"><span style="mso-list:Ignore">2.<span style="font:7.0pt &quot;Times New Roman&quot;"></span> </span></span>****<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">Компиляция</span>**

**<span style="font-size:16.0pt;
line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:
major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;
color:#24292E">С/</span>****<span lang="EN-US" style="font-size:16.0pt;
line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:
major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;
color:#24292E;mso-ansi-language:EN-US">C</span>****<span style="font-size:
16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:
major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;
color:#24292E">++ -> Ассемблер -> Машинный код</span>**

**<span style="font-size:16.0pt;
line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:
major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;
color:#24292E">Один исходный файл -> Один объектный файл</span>**

**<span style="font-size:16.0pt;line-height:107%;mso-bidi-font-family:Calibri;
mso-bidi-theme-font:minor-latin;color:#24292E"><span style="mso-list:Ignore">3.<span style="font:7.0pt &quot;Times New Roman&quot;"></span> </span></span>****<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">Компоновка</span>**

**<span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Объектные файлы -> Исполняемый файл</span>**

<span class="GramE">**<span style="font-size:16.0pt;
line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:
major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;
color:#24292E">Статическая библиотека</span>** <span style="font-size:16.0pt;
line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:
major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;
color:#24292E">это</span></span> <span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">фактически архив объектных файлов, который используется в процессе статической линковки. В результате статической линковки из многих объектных файлов получается один исполняемый, запускается статическая линковка в момент создания исполняемого файла.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E"></span>

<span class="GramE">**<span style="font-size:16.0pt;
line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:
major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;
color:#24292E">Динамическая библиотека</span>** <span style="font-size:16.0pt;
line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:
major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;
color:#24292E">это</span></span> <span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">фактически исполняемый файл (т.е. DLL и EXE в <span class="SpellE">Windows</span> имеют одинаковый формат). Динамическая линковка запускается в момент создания процесса (когда вы запускаете исполняемый файл на выполнение), линкуются между собой несколько исполняемых файлов каждый раз, когда создается новый процесс. Так же возможна динамическая линковка уже после запуска, т.е. новая библиотека может быть подгружена в адресное пространство ужа работающего процесса.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E"></span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Сделать из статической библиотеки динамическую в принципе можно - необходимо ее (статически) слинковать в динамическую библиотеку, при этом будет создана динамическая библиотека и статическая <span class="SpellE">стаб</span>-библиотека, которую можно использовать в проекте вместо статической библиотеки, чтобы вызывать функции из динамической библиотеки.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E"></span>

**<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Опции компиляции</span>**

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Среди множества опций компиляции и компоновки наиболее часто употребляются следующие:</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">-c <span style="mso-tab-count:1"></span> Эта опция означает, что необходима только компиляция. Из исходных файлов программы создаются объектные файлы в виде <span class="SpellE">name.o</span>. Компоновка не производится.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">-o <span class="SpellE"><span class="GramE">file-name</span></span> <span style="mso-tab-count:1"></span> Использовать <span class="SpellE">file-name</span> в качестве имени для создаваемого файла.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">-<span class="GramE">I <span style="mso-tab-count:1"></span> Используется</span> для добавления ваших собственных каталогов для поиска заголовочных файлов в процессе сборки</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">-<span class="GramE">L <span style="mso-tab-count:1"></span> Передается</span> компоновщику. Используется для добавления ваших собственных каталогов для поиска библиотек в процессе сборки.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">-<span class="GramE">l <span style="mso-tab-count:1"></span> Передается</span> компоновщику. Используется для добавления ваших собственных библиотек для поиска в процессе сборки.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">-<span class="SpellE">shared</span> <span style="mso-tab-count:1"></span> создает общий объектный файл для общей библиотеки.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E"></span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">-<span class="SpellE">fPIC</span></span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E"><span style="mso-tab-count:
1"></span>генерирует независимый от позиции код (PIC) для разделяемых библиотек.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E"></span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E"></span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E"></span>

<span class="SpellE">**<span style="font-size:16.0pt;
line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:
major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;
color:#24292E">ar</span>**</span> <span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">— стандартная утилита <span class="SpellE">Unix</span>, архиватор, не использующий сжатия данных.</span>

<span class="SpellE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">ar</span></span> <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">[<span class="GramE">-]{</span><span class="SpellE">dmpqrtx</span>}[<span class="SpellE">abcilosuvV</span>] [<span class="SpellE">имя_компонента_архива</span>] архив-файлы…</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Пример создания архива</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">$ <span class="SpellE">ar</span> r texts.ar *.<span class="SpellE">txt</span></span>

<span class="SpellE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">ar</span></span> <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">может не только создавать/извлекать файлы из архива, но и модифицировать их.</span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">Содержимое оригинального файла, права доступа, время, владелец и группа сохраняются в архиве и могут быть переопределены при <span class="SpellE">извлечени</span></span>

<span class="GramE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">d <span style="mso-tab-count:1"></span> Удаляет</span></span> <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">модули из архива</span>

<span class="GramE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">m <span style="mso-tab-count:1"></span> Перемещает</span></span> <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">файлы (перемещаются в конец архива)</span>

<span class="GramE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">p <span style="mso-tab-count:1"></span> Выводит</span></span> <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">заданные компоненты архива на стандартный вывод</span>

<span class="GramE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">q <span style="mso-tab-count:1"></span> Добавляет</span></span> <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">файлы в конец архива, без проверки на замещение</span>

<span class="GramE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">r <span style="mso-tab-count:1"></span> Вставляет</span></span> <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">файлы в архив (с замещением)</span>

<span class="GramE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">t <span style="mso-tab-count:1"></span> Показывает</span></span> <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">таблицу, в которой хранится содержание архива, или файлы, что были указаны в качестве параметра и присутствуют в архиве</span>

<span class="GramE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">x <span style="mso-tab-count:1"></span> Извлекает</span></span> <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">компоненты (данные как файлы) из архива</span>

<span class="GramE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">a</span></span><span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E"> <span style="mso-tab-count:1"></span> Добавить новые файлы после одного из существующих в архиве компонента</span>

<span class="GramE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">b</span></span><span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E"> <span style="mso-tab-count:1"></span> Добавить новые файлы перед одним из существующих в архиве компонентов</span>

<span class="GramE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">c</span></span><span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E"> <span style="mso-tab-count:1"></span> Создать архив</span>

<span class="GramE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">f <span style="mso-tab-count:1"></span> Урезает</span></span> <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">имена в архиве для совместимости с другими операционными системами</span>

<span class="GramE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">i</span></span><span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E"> <span style="mso-tab-count:1"></span> Вставить новые файлы перед одним из существующих в архиве компонентов</span>

<span class="GramE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">o <span style="mso-tab-count:1"></span> Восстанавливает</span></span> <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">оригинальную дату компонентов архива, когда они извлекаются</span>

<span class="GramE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">s <span style="mso-tab-count:1"></span> Записывает</span></span> <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">индекс объектного файла в архив или, если он существует, обновляет его, даже если нет других изменений в архиве</span>

<span class="GramE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">u</span></span><span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E"> <span style="mso-tab-count:1"></span> При замещении файлов вставить только те из них, что отличаются от уже имеющихся в архиве</span>

<span class="GramE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">v <span style="mso-tab-count:1"></span> Включает</span></span> <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">режим выдачи подробностей при выполнении операции</span>

<span class="GramE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">V <span style="mso-tab-count:1"></span> Показывает</span></span> <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">версию <span class="SpellE">ar</span></span>

<span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:
&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;mso-bidi-font-family:
Calibri;mso-bidi-theme-font:minor-latin;color:#24292E"></span>

**<span style="font-size:16.0pt;line-height:107%;
mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E"><span style="mso-spacerun:yes"></span>LD_LIBRARY_PATH</span>** <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">- специальной переменная среды, в которой перечисляются все каталоги содержащие пользовательские динамические библиотеки.</span>

<span class="SpellE"><span style="font-size:16.0pt;line-height:
107%;mso-fareast-font-family:&quot;Times New Roman&quot;;mso-fareast-theme-font:major-fareast;
mso-bidi-font-family:Calibri;mso-bidi-theme-font:minor-latin;color:#24292E">echo</span></span> <span style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E">$LD_LIBRARY_PATH</span><span lang="EN-US" style="font-size:16.0pt;line-height:107%;mso-fareast-font-family:&quot;Times New Roman&quot;;
mso-fareast-theme-font:major-fareast;mso-bidi-font-family:Calibri;mso-bidi-theme-font:
minor-latin;color:#24292E;mso-ansi-language:EN-US"></span>

</div>