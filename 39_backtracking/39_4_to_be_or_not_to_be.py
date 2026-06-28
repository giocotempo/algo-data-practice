def shakespearify(sentence: str)->list[str]:
  letters = sentence.split(" ")
  output = []
  used = []
  back_track(0, letters, used, output)
  return output

def back_track(start: int, candidates: list[str], used: list[str], output: list[str]):
  outcome = " ".join(used)
  if outcome not in output:
    output.append(outcome)

  if len(candidates) == len(used):
    return

  if start > len(candidates):
    return

  for i in range(start, len(candidates)):
    c = candidates[i]
    if c not in used:
      used.append(c)
      back_track(i+1, candidates, used, output)
      used.remove(c)

if __name__ == "__main__":
  # Example
  sentence = "I love dogs"
  print(shakespearify(sentence))