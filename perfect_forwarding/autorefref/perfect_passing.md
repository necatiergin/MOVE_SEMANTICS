Türden bağımsız _(generic)_ olarak yazılan bir kodda bir fonksiyona çağrı yapmak ve çağrıdan elde ettiğimiz geri dönüş değerini bir başka fonksiyona mükemmel şekilde göndermek istiyoruz. _(perfectly passing the return value of a function)_<br>
Bunun için özel bie şy yapmamıza gerek yok:

```cpp
bar(foo(t));
```
Böyle bir kod zaten işimizi görüyor. Ancak yukarıdaki örnekte _foo_ fonksiyonunun geri dönüş değerini bir değişkende saklayıp daha sonra bu değeri bir başka fonksiyona mükemmel şekilde göndermek isteyelim:

```cpp
auto x = foo(t);
bar(x);
```
Bu bizim istediğimiz sonucu vermez.bir isimle oluşturulan x ifadesi her zaman Lvalue ifadesidir. Oysa mükemmel gönderimin gerçeklşemesi için değer kategorsiinin ve constluğun korunması gerekir.
İşte bu amaçla dile başka bir öğe eklenmiştir.

auto && r = expr;

Buradaki r referansı "universal referanstır.

Tür çıkarımı fonksiyon şablonu universal referans parametresinde olduğu gibi yapılı.

eğer expr T türünden L value ise auto yerine T& gelir ve reference collapsing ile r değişkeninin türü T& olur. 
eğer expr T türünden R value ise auto yerine T gelir ve r değişkeninin türü T&& olur. 


