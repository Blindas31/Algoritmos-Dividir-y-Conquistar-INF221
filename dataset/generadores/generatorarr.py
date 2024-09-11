import csv
import random
TAMAÑO=1000000000
def generate_random_dataset(size, lower_bound, upper_bound):
    return [random.randint(lower_bound, upper_bound) for _ in range(size)]

def generate_sorted_dataset(size):
    return list(range(size))

def generate_reverse_sorted_dataset(size):
    return list(range(size, 0, -1))

def generate_duplicate_dataset(size, unique_values):
    return [random.choice(range(unique_values)) for _ in range(size)]

def generate_special_values_dataset(size):
    return [0] * (size // 2) + [1] * (size // 2)

def generate_peaks_and_valleys_dataset(size):
    return [i if i % 2 == 0 else size - i for i in range(size)]

def save_dataset_to_txt(dataset, filename):
    with open(filename, 'w') as file:
        for i, number in enumerate(dataset):
            if i < TAMAÑO - 1:
                file.write(f"{number}\n")
            else:
                file.write(f"{number}") 
            
def save_dataset_to_csv(dataset, filename):
    with open(filename, 'w', newline='') as file:
        writer = csv.writer(file)
        for number in dataset:
            writer.writerow([number])

random_dataset = generate_random_dataset(TAMAÑO, 0, TAMAÑO)
save_dataset_to_txt(random_dataset, 'random_dataset1000000000.txt')
#random_dataset = generate_sorted_dataset(TAMAÑO)
#save_dataset_to_txt(random_dataset, 'sort_dataset1000000000.txt')
#random_dataset = generate_reverse_sorted_dataset(TAMAÑO)
#save_dataset_to_txt(random_dataset, 'reversesort_dataset1000000000.txt')
#random_dataset = generate_duplicate_dataset(TAMAÑO, 0, TAMAÑO)
#save_dataset_to_txt(random_dataset, 'random_datasetdupli.txt')
#random_dataset = generate_peaks_and_valleys_dataset(TAMAÑO)
# #save_dataset_to_txt(random_dataset, 'peaks_dataset1000000000.txt')