# 2048

---GAME 2048---

*Cách chơi:

    +bắt đầu game sẽ vào menu start.
    +nháy đúp chuột vào PLAY GAME để bắt đầu chơi hoặc EXIT để thoát khỏi trò chơi.
    +Vào game sử dụng các phím lên, xuống, trái, phải trên bàn phím để di chuyển các ô số trong bảng 4x4 
    của game cố gắng đạt đến 2048.

*Luật chơi:

    +khi bấm phím lên, các ô số sẽ dồn lên trên cùng của bảng theo từng cột của bảng số (các phím còn lại tương tự)
    +khi 2 ô gần nhau nhất có số giống nhau thì sẽ gộp lại với nhau để tạo thành số mới có giá trị gấp đôi số cũ
    +khi bảng 4x4 đầy và người chơi không có cách nào di chuyển các ô số bên trong thì kết thúc game (game over)
    +khi người chơi tạo ra được ô số 2048 thì người chơi giành chiến thắng (you win)

*Giải thích code trong game

-game được chia modul như main.cpp, Game.cpp, draw.cpp, Texture.cpp... để xử lý các chức năng riêng trong game
-các hàm trong game
 +main.cpp: chạy chương trình

 +Texture.h

    void logSDLError() : báo lỗi
    void initSDL() : khởi tạo SDL cho game
    void quitSDL() : thoát khỏi SDL
    SDL_Texture* loadTexture() : load ảnh
    void renderTexture() : "............................."
    void renderTexture() : hiển thị ảnh vào 1 vị trí nào đó
 +block.h

   khởi tạo class Block xử lí: trả về giá trị, so sánh 2 giá trị và cộng 2 giá trị

+draw.h

        void loadBackground () : load ảnh background và các chữ :GAME 2048...NEW GAME, EXIT,...
	void loadStart(): load giao diện khi bắt đầu game
	void loadNew(): load chữ NEW GAME với màu khác để tạo hiệu ứng khi di chuyển chuột tới
	void loadPlay(): load chữ PLAY GAME ở giao diện bắt đầu game với màu khác
	void loadExit(): load chữ EXIT với màu khác
	void loadNumber () : load các số 2,4,8,16....
	void LoadText(): load chữ ra màn hình
	void gameOver_WinGame(): hiển thị "YOU WIN" khi đạt tới 2048 ,"GAME OVER" khi thua

+Game.h
    void startGame(SDL_Renderer *renderer, SDL_Window *window): hàm chạy game
    void showGame(SDL_Renderer *renderer): hiện thị ảnh bkg và các số khi chơi game;

    void showScore(SDL_Renderer *renderer,int score): hiện thị điểm khi chơi
    void showHigh(SDL_Renderer *renderer,int highScore): hiện thị điểm cao nhất
    int mouseEvent(SDL_Renderer *renderer): xử lí chuột khi thắng hoặc thua

    Block** createtab() : khởi tạo bảng 4X4 ban đầu


    bool checkWin(Block **&tab) : kiểm tra xem đã thắng hay chưa
    bool checkPut(Block **&tab) : kiểm tra xem bảng còn vị trí trống ko
    bool checkLose(Block **&tab): kiểm tra xem đã thua chưa


    bool rushUp(Block **&tab)
    int moveUp(Block **&tab);
    bool rushDown(Block **&tab);
    int moveDown(Block **&tab);     : Các hàm xử lí lên xuống trái phải
    bool rushRight(Block **&tab);   :
    int moveRight(Block **&tab);
    bool rushLeft(Block **&tab);
    int moveLeft(Block **&tab);

    void themSo(Block **&tab) : thêm số khi di chuyển
    void getHighScore() :nhận vào highScore từ tệp highScore.txt
    void saveHighScore() : lưu highScore vào tệp
    void restart(): chạy lại từ đầu

    bool Check(const int &x, const int &y, const SDL_Rect &_rect): kiểm tra xem chuột đã tới vị trí nào đó hay chưa
