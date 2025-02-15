SELECT CATEGORY, sum(s.sales) as TOTAL_SALES
from BOOK b join BOOK_SALES s on b.book_id=s.book_id
where year(s.SALES_DATE)=2022 and month(s.SALES_DATE)=1
group by b.CATEGORY
order by b.CATEGORY asc

# select *
# from BOOK b join BOOK_SALES s on b.book_id=s.book_id
