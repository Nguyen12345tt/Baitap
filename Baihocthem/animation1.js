document.addEventListener('DOMContentLoaded', () => {
    const flag = document.getElementById('flag');

    const startAnimation = () => {
        const flagWidth = flag.offsetWidth;
        const flagHeight = flag.offsetHeight;
        const segmentWidth = 5; // Chiều rộng của mỗi cột
        const numSegments = Math.ceil(flagWidth / segmentWidth);
        const amplitude = 20; // Biên độ sóng
        const speed = 0.015; // Tốc độ sóng
        const frequency = 0.04; // Tần số sóng

        for (let i = 0; i < numSegments; i++) {
            const segment = document.createElement('div');
            segment.className = 'flag-segment';
            segment.style.left = i * segmentWidth + 'px';
            flag.appendChild(segment);

            const animateWave = () => {
                const x = i * segmentWidth;
                const yOffset = Math.sin(x * frequency + Date.now() * speed) * amplitude;
                segment.style.transform = `translateY(${yOffset}px)`;
                requestAnimationFrame(animateWave);
            };

            animateWave();
        }
    };

    // Gọi startAnimation khi DOM đã được tải hoàn toàn
    startAnimation();
});