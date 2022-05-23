
## Hướng dẫn cài đặt (Windows 64bit)

### Yêu cầu: MinGw-w64

Xem Hướng dẫn cài MingGw-w64 tại [đây](https://www.msys2.org/)  

Clone repository này về  
Vào thư mục cmake-build chạy file main.exe

## Mô tả

**Pi's Adventure** là một tựa game 2D Platformer (lấy ý tưởng từ các game cổ điển **Mario**, **Kirby**)  
Nhân vật chính cố gắng vượt qua màn chơi thu thập pickup và chest

## Chức năng

- Chọn Level
- Chọn nhân vật
- Nhảy 2 lần
- Thu thập Pickup
- Mở Chest
- Tiêu diệt quái vật

## Hướng dẫn chơi

Sử dụng phím **W, A** để di chuyển, **S** để nhảy (có thể **Double Jump**)  
Cố gắng thu thập thật nhiều pickup, chest và tránh đụng vào enemy, spike, rơi xuống vực  
**Chú ý**: Nếu nhân vật va chạm với enemy theo chiều ngang sẽ chết  
Tuy nhiên nếu nhân vật nhảy lên enemy sẽ tiêu diệt được enemy

## Video minh hoạ

[Link Youtube](https://www.youtube.com/watch?v=i3FIgqlRoOg)

## Kỹ thuật sử dụng

- Sử dụng container như vector, map, stack
- Sử dụng Smart Pointer
- Sử dụng Template
- Lập trình đối tượng
- Sử dụng Thư viện đồ hoạ SFML
- Sử dụng Thư viện jsoncpp để xử lý file .json
- Sử dụng phần mềm Tiled để tạo màn chơi
- Cấu trúc Entity - Component - System

## Bài học

- Cách cấu trúc, chia file trong một chương trình
- Học được cấu trúc Entity - Component - System
- Cách cấu trúc game loop để game chạy ổn định trên nhiều thiết bị với frame rate khác nhau

## Hướng phát triển

- Thêm Level
- Đa dạng thêm enemy, pickup
- Fix một số bug nho nhỏ
- Đa dạng âm thanh

