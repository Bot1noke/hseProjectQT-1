import matplotlib.pyplot as plt
import pandas as pd

# Пример данных из таблицы
data = {
    'x': [1, 2, 3, 4, 5],
    'y': [10, 20, 25, 30, 40]
}
df = pd.DataFrame(data)

# Создание графика
plt.plot(df['x'], df['y'])
plt.xlabel('X axis')
plt.ylabel('Y axis')
plt.title('Sample Plot')
# Сохранение графика как изображение
plt.savefig('plot.png', dpi=150)
