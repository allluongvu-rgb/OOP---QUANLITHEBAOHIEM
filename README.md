# Hệ thống Quản lý Thẻ Bảo hiểm (C++ OOP)

## 📌 Tổng quan dự án
Kho lưu trữ này chứa ứng dụng console C++ được thiết kế để quản lý hồ sơ bảo hiểm y tế. Mục tiêu cốt lõi của dự án là thể hiện sự am hiểu sâu sắc và khả năng áp dụng thực tế các nguyên lý **Lập trình Hướng đối tượng (OOP)**. 

Hệ thống xử lý linh hoạt các loại hợp đồng bảo hiểm khác nhau (Nội trú và Ngoại trú), tự động tính toán mức phí, hạn mức bồi thường và hỗ trợ trích xuất số liệu thống kê đa điều kiện.

## 🚀 Ứng dụng Nguyên lý OOP
* **Kế thừa & Trừu tượng (Inheritance & Abstraction):** Thiết kế lớp cơ sở trừu tượng `THEBAOHIEM` chứa các thuộc tính và phương thức cốt lõi. Mở rộng nghiệp vụ hệ thống thông qua các lớp dẫn xuất `THENOITRU` (Nội trú) và `THENGOAITRU` (Ngoại trú).
* **Đa hình (Polymorphism):** Vận dụng hàm ảo (`virtual`) và kỹ thuật ghi đè (overriding) (ví dụ: `mucboithuong()`, `mucphicoban()`) để hệ thống tự động nhận diện và tính toán đúng công thức bồi thường cho từng loại thẻ ngay trong quá trình thực thi (runtime).
* **Đóng gói (Encapsulation):** Bảo vệ an toàn dữ liệu nội bộ của đối tượng (Mã số, Tên, Ngày phát hành, Mức phí) bằng cách sử dụng các phạm vi truy cập chuẩn mực (`protected`, `private`).
* **Quản lý Bộ nhớ động (Dynamic Memory Allocation):** Ứng dụng mảng con trỏ đối tượng (`THEBAOHIEM* ds[]`) để cấp phát và thu hồi vùng nhớ một cách an toàn bằng lệnh `new` và `delete`, kiểm soát triệt để hiện tượng rò rỉ bộ nhớ (memory leaks) đặc trưng trong C++.

## ⚙️ Tính năng nổi bật
* Nhập và lưu trữ dữ liệu hàng loạt đối với nhiều loại hồ sơ bảo hiểm khác nhau.
* Tự động tính toán mức bồi thường tối đa cho từng khách hàng theo chính sách thẻ.
* Thống kê tổng quỹ dự phòng bồi thường của toàn bộ hệ thống.
* Tính toán mức phí đóng trung bình và tự động lọc danh sách các khách hàng có mức phí thấp hơn ngưỡng trung bình.
* Rà soát và trích xuất thông tin khách hàng nội trú có số ngày đăng ký nằm viện thấp nhất.

## 🛠️ Công nghệ sử dụng
* **Ngôn ngữ:** C++
* **Trọng tâm:** Thiết kế Lập trình Hướng đối tượng (OOP), Quản lý bộ nhớ động.
