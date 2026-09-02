from collections import Counter


def solution(k, tangerine):
    # 귤 크기별 개수를 센다.
    counts = Counter(tangerine)

    # 많이 존재하는 크기부터 선택한다.
    frequencies = sorted(counts.values(), reverse=True)

    selected_count = 0
    type_count = 0

    for frequency in frequencies:
        selected_count += frequency
        type_count += 1

        if selected_count >= k:
            return type_count