$(document).ready(function() {
    // Hàm này đảm bảo code jQuery chỉ chạy sau khi tài liệu HTML đã tải xong

    const apiUrl = 'https://67be8b50b2320ee05010771f.mockapi.io/api/v1/Sanpham1'; // MockAPI
    // Khai báo hằng số apiUrl chứa URL của API mockAPI

    // Hàm hiển thị danh sách loại sản phẩm
    function displayCategories() {
        $.ajax({
            // Sử dụng hàm $.ajax của jQuery để gửi yêu cầu HTTP đến API
            url: apiUrl,
            // Chỉ định URL của API
            method: 'GET',
            // Chỉ định phương thức HTTP là GET (lấy dữ liệu)
            success: function(data) {
                // Hàm này được gọi khi yêu cầu thành công
                let tableBody = $('#categoryTable tbody');
                // Lấy phần tử <tbody> của bảng HTML có id là categoryTable
                tableBody.empty(); // Xóa dữ liệu cũ
                // Xóa tất cả các hàng hiện có trong bảng

                data.forEach(category => {
                    // Lặp qua từng đối tượng sản phẩm trong dữ liệu trả về
                    tableBody.append(`
                        // Thêm một hàng mới vào bảng
                        <tr>
                            <td>${category.id}</td>
                            // Hiển thị id của sản phẩm
                            <td>${category.name}</td>
                            // Hiển thị tên của sản phẩm
                            <td>
                                <button class="edit" data-id="${category.id}">Sửa</button>
                                <button class="delete" data-id="${category.id}">Xóa</button>
                            </td>
                        </tr>
                    `);
                });
            },
            error: function(error) {
                // Hàm này được gọi khi yêu cầu thất bại
                console.error('Lỗi khi lấy dữ liệu:', error);
                // In thông báo lỗi ra console
            }
        });
    }

    // Gọi hàm hiển thị khi trang được tải
    displayCategories();
    // Gọi hàm displayCategories() để hiển thị danh sách sản phẩm

    // Hàm thêm loại sản phẩm
    $('#addCategory').click(function() {
        // Gắn một trình xử lý sự kiện click cho nút có id là addCategory
        let categoryName = prompt('Nhập tên loại sản phẩm:');
        // Hiển thị hộp thoại prompt để người dùng nhập tên sản phẩm
        if (categoryName) {
            // Nếu người dùng nhập tên sản phẩm
            $.ajax({
                // Sử dụng hàm $.ajax để gửi yêu cầu POST đến API
                url: apiUrl,
                // Chỉ định URL của API
                method: 'POST',
                // Chỉ định phương thức HTTP là POST (thêm dữ liệu)
                data: { name: categoryName },
                // Gửi tên sản phẩm trong dữ liệu yêu cầu
                success: function() {
                    // Hàm này được gọi khi thêm thành công
                    displayCategories(); // Hiển thị lại danh sách
                    // Gọi displayCategories() để cập nhật danh sách
                },
                error: function(error) {
                    // Hàm này được gọi khi thêm thất bại
                    console.error('Lỗi khi thêm:', error);
                    // In thông báo lỗi ra console
                }
            });
        }
    });

    // Hàm xóa loại sản phẩm
    $(document).on('click', '.delete', function() {
        // Gắn trình xử lý sự kiện click cho các nút có class là delete
        let categoryId = $(this).data('id');
        // Lấy id của sản phẩm từ thuộc tính data-id của nút
        if (confirm('Bạn có chắc chắn muốn xóa?')) {
            // Hiển thị hộp thoại confirm để xác nhận xóa
            $.ajax({
                // Sử dụng hàm $.ajax để gửi yêu cầu DELETE đến API
                url: `${apiUrl}/${categoryId}`,
                // Tạo URL yêu cầu xóa sản phẩm cụ thể
                method: 'DELETE',
                // Chỉ định phương thức HTTP là DELETE (xóa dữ liệu)
                success: function() {
                    // Hàm này được gọi khi xóa thành công
                    displayCategories();
                    // Gọi displayCategories() để cập nhật danh sách
                },
                error: function(error) {
                    // Hàm này được gọi khi xóa thất bại
                    console.error('Lỗi khi xóa:', error);
                    // In thông báo lỗi ra console
                }
            });
        }
    });

    // Hàm sửa loại sản phẩm
    $(document).on('click', '.edit', function() {
        // Gắn trình xử lý sự kiện click cho các nút có class là edit
        let categoryId = $(this).data('id');
        // Lấy id của sản phẩm từ thuộc tính data-id của nút
        let newName = prompt('Nhập tên mới:');
        // Hiển thị hộp thoại prompt để người dùng nhập tên mới
        if (newName) {
            // Nếu người dùng nhập tên mới
            $.ajax({
                // Sử dụng hàm $.ajax để gửi yêu cầu PUT đến API
                url: `${apiUrl}/${categoryId}`,
                // Tạo URL yêu cầu sửa sản phẩm cụ thể
                method: 'PUT',
                // Chỉ định phương thức HTTP là PUT (cập nhật dữ liệu)
                data: { name: newName },
                // Gửi tên mới của sản phẩm trong dữ liệu yêu cầu
                success: function() {
                    // Hàm này được gọi khi sửa thành công
                    displayCategories();
                    // Gọi displayCategories() để cập nhật danh sách
                },
                error: function(error) {
                    // Hàm này được gọi khi sửa thất bại
                    console.error('Lỗi khi sửa:', error);
                    // In thông báo lỗi ra console
                }
            });
        }
    });
});