SELECT AUTHOR_ID, (
    select a.AUTHOR_NAME
    from author a
    where a.author_id = b.author_id
) as AUTHOR_NAME, CATEGORY, (sum(price*sales)) as TOTAL_SALES
from BOOK b join BOOK_SALES s on b.book_id=s.book_id
where year(SALES_DATE)=2022 and month(SALES_DATE)=1
group by category, author_id
order by AUTHOR_ID, CATEGORY desc