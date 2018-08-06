#ifndef SEQUENCE_DETAIL_HPRIME_FAYWUH_AGGREGATOR_HPP
#define SEQUENCE_DETAIL_HPRIME_FAYWUH_AGGREGATOR_HPP

#include <cmath>
#include <Sequence/StateCounts.hpp>

namespace Sequence
{
    namespace detail
    {
        struct hprime_faywuh_aggregator
        {
            unsigned S;
            double pi, theta;
            const double power;
            hprime_faywuh_aggregator(const double p)
                : S{ 0 }, pi{ 0.0 }, theta{ 0.0 }, power{ p }
            {
            }

            inline void
            operator()(const Sequence::StateCounts &c)
            {
                unsigned nstates = 0;
                bool refseen = false;
                double temp = 0.0;
                double homozygosity = 0.0;
                for (std::size_t i = 0; i < c.counts.size(); ++i)
                    {
                        auto ci = c.counts[i];
                        if (ci > 0)
                            {
                                homozygosity
                                    += static_cast<double>(ci * (ci - 1));
                                ++nstates;
                                if (static_cast<std::int8_t>(i) != c.refstate)
                                    {
                                        temp += std::pow(
                                            static_cast<double>(ci), power);
                                    }
                                else
                                    {
                                        refseen = true;
                                    }
                            }
                    }
                if (nstates > 2)
                    {
                        throw std::runtime_error(
                            "site has more than one derived state");
                    }

                if (nstates > 1)
                    {
                        ++S;
                    }
                if (refseen)
                    {
                        double nnm1 = static_cast<double>(c.n * (c.n - 1));
                        pi += 1.0 - homozygosity / nnm1;
                        theta += temp / nnm1;
                    }
            }
        };
    } // namespace detail
} // namespace Sequence

#endif
