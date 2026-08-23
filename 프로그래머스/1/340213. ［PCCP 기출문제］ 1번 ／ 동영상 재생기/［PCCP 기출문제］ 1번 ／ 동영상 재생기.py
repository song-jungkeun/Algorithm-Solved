def solution(video_len, pos, op_start, op_end, commands):
    def to_seconds(time):
        minute, second = map(int, time.split(":"))
        return minute * 60 + second

    def to_time(seconds):
        minute = seconds // 60
        second = seconds % 60
        return f"{minute:02d}:{second:02d}"

    video_len_sec = to_seconds(video_len)
    current = to_seconds(pos)
    op_start_sec = to_seconds(op_start)
    op_end_sec = to_seconds(op_end)

    def skip_opening(current):
        if op_start_sec <= current <= op_end_sec:
            return op_end_sec
        return current

    current = skip_opening(current)

    for command in commands:
        current = skip_opening(current)

        if command == "prev":
            current = max(0, current - 10)
        elif command == "next":
            current = min(video_len_sec, current + 10)

        current = skip_opening(current)

    return to_time(current)