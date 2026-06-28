def subset_enumeration(S: list[str])->list[list[str]]:
  candidates = set()
  output = []
  back_track(S, candidates, output)
  return [list(o)[:] for o in output]

def back_track(S: list, candidates: set, output: list):
  if candidates not in output:
    output.append(set(list(candidates)[:]))

  if len(candidates) == len(S):
    return

  for s in S:
    if s not in candidates:
      candidates.add(s)
      back_track(S, candidates, output)
      candidates.remove(s)
        
if __name__ == "__main__":
  # Example
  S = ["x", "y", "z"]
  print(subset_enumeration(S))