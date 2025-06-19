# 🧮 Matrix Operations in C / C Dilinde Matris İşlemleri

## 🇹🇷 Proje Açıklaması

Bu C programı, rastgele oluşturulmuş 3x3 boyutunda iki matris üzerinde çeşitli işlemler gerçekleştiren etkileşimli bir menü sunar. Program, aşağıdaki işlemleri destekler:

- İki matrisi eleman bazında çarpma  
- En büyük ve en küçük elemanların değer ve konumlarını bulma  
- Ortalamaya en yakın satırı belirleme  
- Köşegen toplamlarını hesaplama  
- Her satır ve sütunun toplamını ayrı ayrı gösterme

## EN Project Description

This C program presents an interactive menu that performs various operations on two randomly generated 3x3 matrices. Supported operations include:

- Element-wise multiplication of two matrices  
- Finding the maximum and minimum values with their positions  
- Identifying the row closest to the matrix average  
- Calculating diagonal sums  
- Displaying individual row and column sums

---

## ▶️ Kullanım / Usage

Program çalıştırıldığında iki matris rastgele oluşturulur ve ardından kullanıcıdan işlem seçmesi istenir.  
When the program starts, two matrices are generated randomly and the user is prompted to select an operation.

**Menü / Menu:**

- `1` - Multiply Two Matrices (element-wise)  
- `2` - Max and Min Element Indices  
- `3` - Find Row Closest to Average  
- `4` - Diagonal Sums  
- `5` - Row and Column Sums  
- `6` - Exit

---

## ⚙️ Derleme ve Çalıştırma / Compile and Run

```bash
gcc main.c -o matrix_app
./matrix_app
