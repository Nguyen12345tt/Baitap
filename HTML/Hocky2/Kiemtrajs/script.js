document.addEventListener('DOMContentLoaded', () => {
    // 1. Lấy phần tử tbody của bảng, sử dụng optional chaining để tránh lỗi nếu bảng không tồn tại
    const productTable = document.getElementById('productTable')?.querySelector('tbody');

    // 2. Kiểm tra xem bảng và tbody có tồn tại hay không
    if (!productTable) {
        console.error("Không tìm thấy bảng hoặc tbody.");
        return; // Dừng thực thi nếu không tìm thấy bảng
    }

    // 3. Sử dụng Fetch API để lấy dữ liệu từ API
    fetch('https://fakestoreapi.com/products')
        .then(response => {
            // 4. Kiểm tra xem phản hồi có thành công hay không
            if (!response.ok) {
                throw new Error(`HTTP error! status: ${response.status}`); // Ném lỗi nếu phản hồi không thành công
            }
            return response.json(); // Chuyển đổi dữ liệu nhận được sang định dạng JSON
        })
        .then(products => {
            // 5. Duyệt qua từng sản phẩm trong mảng products
            products.forEach(product => {
                // 6. Tạo một hàng mới trong bảng
                const row = productTable.insertRow();

                // 7. Tạo các ô dữ liệu cho từng cột (ID, Hình ảnh, Tiêu đề, Mô tả, Giá)
                const cells = [
                    row.insertCell(), // Ô ID
                    row.insertCell(), // Ô Hình ảnh
                    row.insertCell(), // Ô Tiêu đề
                    row.insertCell(), // Ô Mô tả
                    row.insertCell()  // Ô Giá
                ];

                // 8. Gán ID của sản phẩm vào ô ID
                cells[0].textContent = product.id;

                // 9. Tạo và hiển thị hình ảnh sản phẩm
                const image = document.createElement('img');
                image.src = product.image;
                image.alt = product.title;
                image.style.maxWidth = '100px'; // Giới hạn kích thước ảnh
                cells[1].appendChild(image); // Thêm ảnh vào ô Hình ảnh

                // 10. Gán tiêu đề sản phẩm vào ô Tiêu đề
                cells[2].textContent = product.title;

                // 11. Rút gọn mô tả nếu quá dài và gán vào ô Mô tả
                const shortDescription = product.description.length > 100 ? product.description.substring(0, 100) + '...' : product.description;
                cells[3].textContent = shortDescription;

                // 12. Gán giá sản phẩm vào ô Giá
                cells[4].textContent = product.price;
            });
        })
        .catch(error => {
            // 13. Xử lý lỗi nếu có
            console.error('Lỗi khi lấy dữ liệu sản phẩm:', error);
            const errorDiv = document.createElement('div');
            errorDiv.textContent = 'Đã có lỗi xảy ra khi lấy dữ liệu sản phẩm. Vui lòng thử lại sau.';
            productTable.parentNode?.insertBefore(errorDiv, productTable); // Hiển thị thông báo lỗi trước bảng
        });
});
