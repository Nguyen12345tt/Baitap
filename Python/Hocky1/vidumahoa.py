def ma_hoa(van_ban, bang_ma):
    van_ban_ma_hoa = ""
    for ky_tu in van_ban:
        if ky_tu in bang_ma:
            van_ban_ma_hoa += bang_ma[ky_tu]
        else:
            van_ban_ma_hoa += ky_tu
    return van_ban_ma_hoa

def giai_ma(van_ban_ma_hoa, bang_ma):
    bang_ma_dao = {v: k for k, v in bang_ma.items()} 
    van_ban_giai_ma = ""
    for ky_tu_ma_hoa in van_ban_ma_hoa:
        if ky_tu_ma_hoa in bang_ma_dao:
            van_ban_giai_ma += bang_ma_dao[ky_tu_ma_hoa]
        else:
            # Giữ nguyên ký tự nếu không có trong bảng mã đảo ngược
            van_ban_giai_ma += ky_tu_ma_hoa
    return van_ban_giai_ma

# --- Chương trình chính ---
if __name__ == "__main__":
    bang_ma_ky_tu = {
        'a': '!',
        'b': '@',
        'c': '#',
        'd': '$',
        'e': '%',
        'f': '^',
        'g': '&',
        'h': '*',
        'i': '(',
        'j': ')',
        'k': '_',
        'l': '+',
        'm': '=',
        'n': '-',
        'o': '[',
        'p': ']',
        'q': '{',
        'r': '}',
        's': ';',
        't': ':',
        'u': '\'',
        'v': '"',
        'w': '<',
        'x': '>',
        'y': ',',
        'z': '.',
        ' ': ' ',  # Giữ nguyên khoảng trắng
        'A': '1',
        'B': '2',
        'C': '3',
        'D': '4',
        'E': '5',
        'F': '6',
        'G': '7',
        'H': '8',
        'I': '9',
        'J': '0',
        'K': 'q',
        'L': 'w',
        'M': 'e',
        'N': 'r',
        'O': 't',
        'P': 'y',
        'Q': 'u',
        'R': 'i',
        'S': 'o',
        'T': 'p',
        'U': 'a',
        'V': 's',
        'W': 'd',
        'X': 'f',
        'Y': 'g',
        'Z': 'h',
        '0': 'z',
        '1': 'x',
        '2': 'c',
        '3': 'v',
        '4': 'b',
        '5': 'n',
        '6': 'm',
        '7': 'l',
        '8': 'k',
        '9': 'j',
        '.': '?',
        ',': '/',
        '?': '\\',
        '!': '`',
        '@': '~',
        '#': '±',
        '$': '§',
        '%': '°',
        '^': '¬',
        '&': '¢',
        '*': '£',
        '(': '€',
        ')': '¥',
        '_': 'µ',
        '+': '>',
        '=': '<',
        '-': '≥',
        '[': '≤',
        ']': '÷',
        '{': '×',
        '}': '√',
        ';': '∫',
        ':': '∑',
        '\'': '∏',
        '"': '∂',
        '<': '∆',
        '>': '∇',
        ',': '/',
        '.': '?',
    }

    while True:
        print("\nChọn thao tác:")
        print("1. Mã hóa văn bản")
        print("2. Giải mã văn bản")
        print("3. Thoát")

        lua_chon = input("Nhập lựa chọn của bạn: ")

        if lua_chon == '1':
            van_ban_goc = input("Nhập văn bản cần mã hóa: ")
            van_ban_ma_hoa = ma_hoa(van_ban_goc, bang_ma_ky_tu)
            print("Văn bản đã mã hóa:", van_ban_ma_hoa)
        elif lua_chon == '2':
            van_ban_ma_hoa_nhap = input("Nhập văn bản cần giải mã: ")
            van_ban_giai_ma = giai_ma(van_ban_ma_hoa_nhap, bang_ma_ky_tu)
            print("Văn bản đã giải mã:", van_ban_giai_ma)
        elif lua_chon == '3':
            print("Cảm ơn bạn đã sử dụng chương trình!")
            break
        else:
            print("Lựa chọn không hợp lệ. Vui lòng chọn lại.")