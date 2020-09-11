Closing Prices of European Stock Indices (1991-1998)
========================================================
author: Yash Kumar Singh
date: September 2, 2017
autosize: true


Code
========================================================


```r
library(plotly)
library(tidyr)
library(dplyr)
data("EuStockMarkets")
stocks <- as.data.frame(EuStockMarkets) %>%
  gather(index, price) %>%
  mutate(time = rep(time(EuStockMarkets), 4))
plot_ly(stocks, x = ~time, y = ~price, color = ~index, mode = "lines")
```

Plot
========================================================



```
Error in file(con, "rb") : cannot open the connection
```
