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
Bu bizim istediğimizi sağlamaz. Bir isimle _(identifier)_ oluşturulan _x_ ifadesinin değer kategorisi her zaman _Lvalue_'dur. Oysa mükemmel gönderimin sağlanması için ifadenin değer kategorisinin ve _const_'luğunun korunması gerekir.
İşte bu amaçla dile başka bir öğe eklenmiştir.

```cpp
auto && r = expr;
```

Buradaki r referansı "universal referanstır. Tür çıkarımı fonksiyon şablonu _"universal reference"_ parametresinde olduğu gibi yapılır.

- eğer _expr_ _T_ türünden _L value_ ise _auto_ yerine _T&_ gelir ve _reference collapsing_ ile _r_ değişkeninin türü _T&_ olur. 
- eğer _expr_ _T_ türünden _R value_ ise _auto_ yerine _T_ gelir ve _r_ değişkeninin türü _T&&_ olur. 


