import sys
import numpy as np
from scipy import stats
# Lấy hai tham số từ dòng lệnh
a = int(sys.argv[1])




# Số lượng mẫu, tổng giá trị của các mẫu, cận dưới và cận trên của các giá trị mẫu
num_samples = 6
total_value = a
lower_bound = 0
upper_bound = 12000

# Tính giá trị trung bình và độ lệch chuẩn
mean = total_value / num_samples
std_dev = (mean - lower_bound) / 3  # Giả sử rằng 99.7% dữ liệu nằm trong khoảng 3 độ lệch chuẩn từ giá trị trung bình

# Tạo ra các mẫu ngẫu nhiên tuân theo phân phối chuẩn
samples = np.random.normal(mean, std_dev, num_samples)

# Chuẩn hóa các mẫu sao cho tổng của chúng bằng với total_value
samples = samples * total_value / np.sum(samples)

# Đảm bảo rằng tất cả các mẫu đều nằm trong khoảng từ lower_bound đến upper_bound
samples = np.clip(samples, lower_bound, upper_bound)
samples = np.round(samples, 0)

# Kiểm tra xem liệu các mẫu này có tuân theo phân phối chuẩn không bằng cách sử dụng kiểm định Shapiro-Wilk
stat, p = stats.shapiro(samples)
alpha = 0.05
if p < alpha:  # null hypothesis: x comes from a normal distribution
    print("Theo kiểm định Shapiro-Wilk, các mẫu không tuân theo phân phối chuẩn")
else:
    print("Theo kiểm định Shapiro-Wilk, các mẫu có thể tuân theo phân phối chuẩn")

# Kiểm tra xem liệu các mẫu này có tuân theo phân phối chuẩn không bằng cách sử dụng kiểm định Kolmogorov-Smirnov
stat, p = stats.kstest(samples, 'norm')
if p < alpha:  # null hypothesis: x comes from a normal distribution
    print("Theo kiểm định Kolmogorov-Smirnov, các mẫu không tuân theo phân phối chuẩn")
else:
    print("Theo kiểm định Kolmogorov-Smirnov, các mẫu có thể tuân theo phân phối chuẩn")


values = samples.astype(int)
max_idx = values.argmax()
    
# Hoán đổi phần tử lớn nhất với phần tử đầu tiên
values[0], values[max_idx] = values[max_idx], values[0]
wf =  open('data.txt','w')
with open('data','w') as wf:
    for x in values:
        wf.write(str(x)+'\n')
# In ra tổng các giá trị của mẫu
#print("Tổng các giá trị của mẫu: ", np.sum(values))
