# TouchGFX Clock - STM32F429I-DISC1

## Mô tả

Triển khai giao diện đồng hồ analog đơn giản trên bo mạch STM32F429I-DISC1 sử dụng TouchGFX. Kim giây được điều khiển qua nút nhấn vật lý và cập nhật thời gian thực bằng FreeRTOS và bộ hẹn giờ phần cứng.

## Tính năng

- Giao diện đồng hồ analog với kim giây quay.  
- Kim giây đứng yên khi không có thao tác.  
- Khi nhấn nút PA0, kim giây sẽ quay với tần số 1 giây/lần.  
- Góc quay được tính dựa trên thời gian hoạt động của hệ thống.  
- Giao tiếp giữa các task trong FreeRTOS sử dụng hàng đợi (Queue).

## Kiến trúc

- **TouchGFX Designer**: Thiết kế giao diện đồng hồ.  
- **STM32CubeIDE**: Môi trường lập trình chính, cấu hình HAL và FreeRTOS.  
- **FreeRTOS**:  
  - `defaultTask` kiểm tra trạng thái nút PA0 và gửi lệnh qua queue.  
  - `Queue1Handle` truyền lệnh 'P' đến giao diện GUI.  
- **Screen1View::handleTickEvent**:  
  - Gọi mỗi frame, nhận lệnh từ queue và cập nhật góc quay kim giây.

## Yêu cầu phần cứng

- Bo mạch STM32F429I-DISC1  
- Cáp USB  
- Màn hình LCD tích hợp tương thích TouchGFX  
- Nút nhấn gắn sẵn trên chân PA0

## Hướng dẫn sử dụng

1. Mở dự án trong **STM32CubeIDE**.  
2. Tùy chỉnh giao diện bằng **TouchGFX Designer** nếu cần.  
3. Biên dịch và nạp chương trình vào bo mạch.  
4. Nhấn nút PA0 để bắt đầu quay kim đồng hồ.

## Trạng thái dự án
- Đã hoàn thành nguyên mẫu chạy ổn định.  
- Có thể mở rộng thêm:  
  - Kim phút và kim giờ  
  - Đồng hồ thực (RTC)  
  - Nút điều khiển trên giao diện TouchGFX
## Giấy phép

Dự án này chỉ phục vụ mục đích học tập, không dùng cho mục đích thương mại.

---
