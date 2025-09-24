import random

def get_user_choice():
    """Hỏi và lấy lựa chọn của người dùng."""
    while True:
        user_choice = input("Nhập lựa chọn của bạn (kéo, búa, bao): ").lower()
        if user_choice in ['kéo', 'búa', 'bao']:
            return user_choice
        else:
            print("Lựa chọn không hợp lệ. Vui lòng thử lại.")

def get_computer_choice():
    """Tạo lựa chọn ngẫu nhiên cho máy tính."""
    return random.choice(['kéo', 'búa', 'bao'])

def determine_winner(user, computer):
    """Xác định người chiến thắng."""
    print(f"\nBạn chọn: {user}")
    print(f"Máy tính chọn: {computer}\n")

    if user == computer:
        return "Hòa!"
    
    # Các trường hợp người dùng thắng
    if (user == 'búa' and computer == 'kéo') or \
       (user == 'kéo' and computer == 'bao') or \
       (user == 'bao' and computer == 'búa'):
        return "Bạn đã thắng!"
    
    # Nếu không hòa và không thắng, thì thua
    return "Bạn đã thua!"

def play_game():
    """Vòng lặp chính của trò chơi."""
    while True:
        user_choice = get_user_choice()
        computer_choice = get_computer_choice()
        
        result = determine_winner(user_choice, computer_choice)
        print(result)
        
        play_again = input("\nBạn có muốn chơi lại không? (có/không): ").lower()
        if play_again != 'có':
            print("Cảm ơn bạn đã chơi!")
            break

if __name__ == "__main__":
    print("Chào mừng bạn đến với trò chơi Oẳn Tù Tì!")
    play_game()
