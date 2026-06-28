def youtube_video_reception(likes: list, dislikes: list, periods: list)->list:
  prefix_sums = []
  cur_sum = 0
  for like, dislike in zip(likes, dislikes):
    if like - dislike > 0:
      cur_sum += 1
    prefix_sums.append(cur_sum)
  
  output = []
  for l, r in periods:
    if l == 0:
      output.append(prefix_sums[r])
    else:
      output.append(prefix_sums[r] - prefix_sums[l-1])
  
  return output

if __name__ == "__main__":
  likes = [6, 3, 4, 8, 7, 2, 6, 5, 0, 1]
  dislikes = [6, 0, 8, 0, 0, 0, 1, 8, 0, 2]
  periods = [[0, 1], [0, 5], [5, 8], [3, 3]]
  print(youtube_video_reception(likes, dislikes, periods))