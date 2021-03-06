
## Hướng dẫn cài đặt (Windows 64bit)

### Yêu cầu: đường dẫn tới thư mục `bin` của MinGw-w64 được thêm vào `environment path`

Xem Hướng dẫn cài MingGw-w64 tại [đây](https://www.msys2.org/)  

Clone repository này hoặc download và extract về máy của bạn  
Vào thư mục `cmake-build` chạy file `main.exe`

## Cách Build lại project

### Bằng CMake

- Thêm đường dẫn đễn thư mục `ninja-win` vào `environment path` 
- Mở terminal trong thư mục `cmake-build` và gõ lệnh `ninja`

### Bằng Makefile

- Mở terminal trong thư mục `make-build` và gõ lệnh `make all`

## Mô tả

**Pi's Adventure** là một tựa game 2D Platformer (lấy ý tưởng từ các game cổ điển **Mario**, **Kirby**)  
Nhân vật chính cố gắng vượt qua màn chơi thu thập pickup và chest

## Chức năng

### Tính năng trong Game

- Chọn Level
- Chọn nhân vật
- Nhảy 2 lần
- Thu thập Pickup
- Mở Chest
- Tiêu diệt quái vật

### Tính năng đồ hoạ

- Nhân vặt có hoạt ảnh riêng ở các trạng thái khác nhau (**Chạy**, **Đứng im**, **Nhảy**, **Nhảy đôi**, **Ngã**)
- Scrolling Background
- Quái vật, Pickup, Chest đều có hoạt ảnh

### Tính năng âm thanh

- Nhạc nền Background
- Âm thanh khi nhảy

## Giao diện người dụng

- Ở **Menu**, nhấn **Play** để chọn màn chơi, nhấn **Tutorial** để xem hướng dẫn, nhấn **Chose Character** để chọn nhân vật
## Hướng dẫn chơi

Sử dụng phím **W, A** để di chuyển, **S** để nhảy (có thể **Double Jump**)  
Cố gắng thu thập thật nhiều pickup, chest và tránh đụng vào enemy, spike, rơi xuống vực  
**Chú ý**: Nếu nhân vật va chạm với enemy theo chiều ngang sẽ chết  
Tuy nhiên nếu nhân vật nhảy lên enemy sẽ tiêu diệt được enemy

## Video minh hoạ

[Link Youtube](https://www.youtube.com/watch?v=i3FIgqlRoOg)

## Kỹ thuật sử dụng

- Sử dụng các container như vector, map, stack
- Sử dụng Smart Pointer để quản lý object game, giảm bớt gánh nặng xử lý memory
- Sử dụng Template
- Lập trình đối tượng, lợi dụng tính đa hình, trừu tượng để xây dựng game Object
- Sử dụng Thư viện đồ hoạ SFML
- Sử dụng Thư viện jsoncpp để xử lý file .json
- Sử dụng phần mềm Tiled để hỗ trợ tạo màn chơi
- Cấu trúc Entity - Component - System [Đọc thêm](https://en.wikipedia.org/wiki/Entity_component_system)
- Sử dụng Finite State Machine để quản lý State của Game
- Sử dụng Singleton Pattern
- Sử dụng Spritesheet để animate các object trong Game

## Bài học

- Cách cấu trúc, chia file trong một chương trình
- Cách build, compile project với CMake hay Makefile không phụ thuộc vào IDE
- Học được cách sử dụng thư viện đồ họa SFML
- Học được cấu trúc Entity - Component - System
- Học được cách build một Game Engine đơn giản có thể sử dụng lại
- Cách cấu trúc game loop để game chạy ổn định trên nhiều thiết bị với frame rate khác nhau

## Hướng phát triển

- Thêm Level
- Đa dạng thêm enemy, pickup
- Fix một số bug nho nhỏ
- Đa dạng âm thanh

