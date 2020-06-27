function[mmr, mmm]=minimax(M)
mmr=max(M')-min(M')
mmm=max(max(M))-min(min(M))