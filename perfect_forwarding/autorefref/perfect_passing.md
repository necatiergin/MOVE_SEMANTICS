Türden bağımsız (generic) olarak yazılan bir kodda bir fonksiyona çağrı yapmak ver buradan elde ettiğimiz değeri bir başka fonksiyona mükemmel şekilde göndermek istiyoruz. 
perfectly passing the return value of a function

 Bunun için özel bie şy yapmamıza gerek yok

bar(foo(t));

böyle bir kod zaten işimizi görüyor. Ancak yukarıdaki örnekte foo işlevinin geri dönüş değerini bir değişkende saklayıp daha sonra bir fonksiyona mükemmel şekilde göndermek isteyelim.

auto x = foo(t);
bar(x);

Bu bizim istediğimiz sonucu vermez.bir isimle oluşturulan x ifadesi her zaman Lvalue ifadesidir. Oysa mükemmel gönderimin gerçeklşemesi için değer kategorsiinin ve constluğun korunması gerekir.
İşte bu amaçla dile başka bir öğe eklenmiştir.

auto && r = expr;

Buradaki r referansı "universal referanstır.

Tür çıkarımı fonksiyon şablonu universal referans parametresinde olduğu gibi yapılı.

eğer expr T türünden L value ise auto yerine T& gelir ve reference collapsing ile r değişkeninin türü T& olur. 
eğer expr T türünden R value ise auto yerine T gelir ve r değişkeninin türü T&& olur. 


