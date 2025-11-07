# 🧪 Giai Thuật Sắp Xếp

Dự án này triển khai và so sánh nhiều **thuật toán sắp xếp** bằng ngôn ngữ C.  
Mục tiêu là giúp người dùng:
- Hiểu cách hoạt động của từng thuật toán sắp xếp.
- Chạy các **bộ test vector** để kiểm thử tính đúng đắn.
- Dễ dàng thêm và kiểm tra các test mới.

---

## 📁 Cấu trúc thư mục

```bash
giai_thuat_sap_xep/
│
├─ src/                   # Mã nguồn các thuật toán sắp xếp
│  ├─ bubble_sort.c
│  ├─ quick_sort.c
│  ├─ insertion_sort.c
│  └─ main.c
│
├─ tests/                 # Thư mục chứa test vector và chương trình kiểm thử
│  ├─ run_tests.c         # Chương trình thực thi các test vector
│  ├─ test_utils.c        # Hàm hỗ trợ đọc, so sánh dữ liệu test
│  ├─ Makefile            # Script biên dịch tự động
│  └─ vectors/            # Danh sách test vector
│     ├─ vector_01.txt
│     ├─ vector_02.txt
│     └─ ...
│
└─ README.md              # File hướng dẫn (file này)
* Yêu cầu môi trường:
Trình biên dịch GCC hoặc Clang
Hệ điều hành: Linux, macOS hoặc Windows (MinGW)
(Tùy chọn) Có make để dùng lệnh biên dịch tự động
* Cách biên dịch: Dùng make (khuyên dùng)
Từ thư mục tests/, chạy:
make
Sau khi biên dịch thành công, bạn sẽ có tệp thực thi run_tests.
* Cách chạy các bộ test vector
- Chạy toàn bộ test vector
./run_tests
Chương trình sẽ tự động tìm tất cả các file trong thư mục tests/vectors/
và chạy từng test vector một.
- Chạy một test vector cụ thể
./run_tests vectors/vector_01.txt
- Cấu trúc file test vector
Mỗi file test vector nên tuân theo định dạng sau:
# Mô tả: Kiểm thử thuật toán sắp xếp tăng dần với 5 phần tử
INPUT: 5 3 9 1 7
EXPECT: 1 3 5 7 9
# : dòng chú thích, không ảnh hưởng đến test
INPUT: : danh sách phần tử đầu vào
EXPECT: : kết quả mong đợi sau khi sắp xếp 
