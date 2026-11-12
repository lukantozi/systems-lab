/* Inner product. Accumulate in temporary; 6 x 6 loop unrolling */
void inner4_unrolled(vec_ptr u, vec_ptr v, data_t *dest)
{
    long i;
    long length = vec_length(u);
    long limit = length - 5;
    data_t *udata = get_vec_start(u);
    data_t *vdata = get_vec_start(v);
    data_t sum = (data_t) 0;
    data_t sum_0 = (data_t) 0;
    data_t sum_1 = (data_t) 0;
    data_t sum_2 = (data_t) 0;
    data_t sum_3 = (data_t) 0;
    data_t sum_4 = (data_t) 0;
    data_t sum_5 = (data_t) 0;

    for (i = 0; i < limit; i += 6) {
        sum_0 = sum_0 + (udata[i + 0] * vdata[i + 0]);
        sum_1 = sum_1 + (udata[i + 1] * vdata[i + 1]);
        sum_2 = sum_2 + (udata[i + 2] * vdata[i + 2]);
        sum_3 = sum_3 + (udata[i + 3] * vdata[i + 3]);
        sum_4 = sum_4 + (udata[i + 4] * vdata[i + 4]);
        sum_5 = sum_5 + (udata[i + 5] * vdata[i + 5]);
    }

    for (; i < length; i++) {
        sum = sum + udata[i] * vdata[i];
    }

    sum += sum_0 + sum_1 + sum_2 + sum_3 + sum_4 + sum_5;
    *dest = sum;
}
