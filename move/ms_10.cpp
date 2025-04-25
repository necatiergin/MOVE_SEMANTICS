/*
std::vector’ün push_back implementasyonu, kabaca şöyle çalışır (basitleştirilmiş):
*/

void push_back(T&& value) {
    if (size_ < capacity_) {
        new (data_ + size_) T(std::move(value)); // Move constructor çağrılır
        ++size_; // Başarılı olursa boyut artırılır
    } else {
        // Reallocation kodu (bu senaryoda geçerli değil)
    }
}

<!---
new (data_ + size_) T(std::move(value)) ifadesi, vector’ün belleğinde yeni bir Person nesnesi oluşturur ve move constructor’ı çağırır.

Eğer move constructor istisna fırlatırsa, bu yapı (placement new) tamamlanamaz ve size_ artırılmaz. 
Vector’ün durumu değişmediği için strong exception guarantee korunur.

Move constructor’ın noexcept olmaması, burada doğrudan bir sorun yaratmaz, çünkü reallocation olmadığı için std::vector kopyalamaya geri dönmek zorunda kalmaz. 
Sadece yeni elemanı taşımaya çalışır ve bu başarısız olursa işlem geri alınabilir.

--->
