const flag = document.getElementById('flag');
const flagWidth = flag.offsetWidth;
const flagHeight = flag.offsetHeight;
const segmentWidth = 5;
const numSegments = Math.ceil(flagWidth / segmentWidth);
const amplitude = 6; // Giảm biên độ một chút
const speed = 0.015;
const frequency = 0.04;

// Xóa các lớp màu ban đầu
const halfRed = flag.querySelector('.half-red');
const halfBlue = flag.querySelector('.half-blue');
if (halfRed) halfRed.style.display = 'none';
if (halfBlue) halfBlue.style.display = 'none';

for (let i = 0; i < numSegments; i++) {
  const segment = document.createElement('div');
  segment.className = 'flag-segment';
  segment.style.left = i * segmentWidth + 'px';
  segment.style.width = segmentWidth + 'px';
  segment.style.height = flagHeight + 'px';
  segment.style.position = 'absolute';
  segment.style.overflow = 'hidden';

  const topColor = document.createElement('div');
  topColor.className = 'segment-top';
  topColor.style.width = '100%';
  topColor.style.height = flagHeight / 2 + 'px';
  topColor.style.backgroundColor = 'red';
  segment.appendChild(topColor);

  const bottomColor = document.createElement('div');
  bottomColor.className = 'segment-bottom';
  bottomColor.style.width = '100%';
  bottomColor.style.height = flagHeight / 2 + 'px';
  bottomColor.style.backgroundColor = 'blue';
  bottomColor.style.position = 'absolute';
  bottomColor.style.bottom = '0';
  segment.appendChild(bottomColor);

  flag.appendChild(segment);

  function animateWave() {
    const x = i * segmentWidth;
    const yOffset = Math.sin(x * frequency + Date.now() * speed) * amplitude;
    topColor.style.transform = `translateY(${yOffset}px)`;
    bottomColor.style.transform = `translateY(${yOffset}px)`;
    requestAnimationFrame(animateWave);
  }

  animateWave();
}