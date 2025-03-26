# Sistem ini mendukung berbagai metode pembayaran, yaitu:
- Pembayaran dengan Kartu Kredit
- Transfer Bank,
- Dompet Digital

Fitur
- Menggunakan pewarisan (inheritance) untuk mendefinisikan kelas induk `Payment` dan kelas turunan untuk metode pembayaran yang berbeda.
- Menerapkan metode:
  -`processPayment()`: Memproses pembayaran dan mengurangi saldo.
  -`validatePayment()`: Memvalidasi detail pembayaran.
  -`refundPayment()`: Mengembalikan dana ke saldo.
- Mengelola saldo statis yang diperbarui setiap transaksi.

Struktur Kelas
1. Kelas Induk: Payment
Atribut:
-`id`: ID transaksi.
-`amount`: Jumlah pembayaran.
-`date`: Tanggal transaksi.
-`status`: Status pembayaran.
-`balance`: Variabel statis yang menunjukkan saldo yang tersedia.

Metode:
-`processPayment()`: Mengurangi saldo jika mencukupi, jika tidak, menampilkan pesan error.
-`validatePayment()`: Metode placeholder untuk validasi pembayaran.
-`refundPayment()`: Mengembalikan jumlah transaksi ke saldo.

2. Kelas Turunan
A. `CreditCardPayment` (Pembayaran Kartu Kredit)
-Atribut: `cardNumber`, `expiryDate`, `cvv`
-Override `processPayment()` untuk menangani transaksi kartu kredit.
B. `BankTransfer` (Transfer Bank)
  -Atribut: `accountNumber`, `bankName`
   Override `processPayment()` untuk menangani transfer bank.
C. `DigitalWallet` (Dompet Digital)
  -Atribut: `walletId`, `provider`
  -Override `processPayment()` untuk menangani transaksi dompet digital.

Cara Kerja
1. Program menginisialisasi saldo awal sebesar `500.0.`
2. Membuat objek untuk transaksi menggunakan `CreditCardPayment`, `BankTransfer`, dan `DigitalWallet`.
3. Memanggil `processPayment()` untuk setiap transaksi.
4. Jika saldo mencukupi, jumlah transaksi dikurangi dari saldo dan saldo diperbarui.
5. Jika pembayaran dibatalkan, jumlah pembayaran dikembalikan ke saldo.

Contoh Output
```
Saldo Awal: 500.0
Memproses pembayaran sebesar 100.5...
Saldo Saat Ini: 399.5
Memproses pembayaran sebesar 200.75...
Saldo Saat Ini: 198.75
Memproses pembayaran sebesar 50.25...
Saldo Saat Ini: 148.5
```

Persyaratan
  -Compiler C++ (misalnya g++ untuk Linux/macOS, MinGW untuk Windows)

Cara Kompilasi dan Menjalankan
  -`g++ digital_payment.cpp -o payment
./payment`

Pengembangan di Masa Depan:
  -Mengimplementasikan validasi pembayaran untuk setiap metode.
  -Menambahkan penanganan error untuk input yang tidak valid.
  -Mengembangkan fitur riwayat transaksi.
